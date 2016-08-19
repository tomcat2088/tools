import sqlite3 as sl
import logger
from datetime import datetime
import os

class SqlBuilder:
    def __init__(self):
        self.sqlLists = []
        self.values = ()
    def build(self):
        spliter = ' '
        return spliter.join(self.sqlLists)
    def select(self,tableName,cols):
        selectList = self.genSelectList(cols)
        sql = str.format('select {0} from {1}',selectList,tableName)
        self.sqlLists.append(sql)
        return self
    def insert(self,tableName,cols,vals):
        if len(cols) != len(vals):
            logger.error('insert len of col is not eq to len of vals')
            return
        processedVals = []
        for val in vals:
            processedVals.append(str.format(r"'{0}'",val))
        spliter = ','
        valuePlaceHolders = []
        for col in cols:
            valuePlaceHolders.append('?')
        sql = str.format('insert into {0} ({1}) values({2})',tableName,spliter.join(cols),spliter.join(valuePlaceHolders))
        self.sqlLists.append(sql)
        self.values = vals
        return self

    def where(self,conditionDict = None):
        if conditionDict == None or len(conditionDict) == 0:
            return self
        sql = "where "
        conditions = []
        for key in conditionDict:
            conditionStr = str.format('{0}\'{1}\' ',key,conditionDict[key])
            conditions.append(conditionStr)
        sql += ' and '.join(conditions)
        self.sqlLists.append(sql)
        return self

    # helper func
    def genSelectList(self,cols):
        spliter = ','
        if len(cols) > 0:
            return spliter.join(cols)
        return '*'

class DataStorageResult:
    def __init__(self,cursor):
        self.cursor = cursor
    def next(self):
        pass
    def val(self,colName):
        pass
    def count(self):
        return self.cursor.rowcount
    def all(self):
        return self.cursor.fetchall()

class DataStorage:
    DataTypePri = 'PRIMARY'
    DataTypeKey = 'KEY'
    DataTypeAsc = 'ASC'
    DataTypeNull = 'NULL'
    DataTypeText = 'TEXT'
    DataTypeInt = 'INTEGER'
    DataTypeReal = 'REAL'
    DataTypeBlob = 'BLOB'
    defaultStorage = None
    def default():
        if DataStorage.defaultStorage == None:
            if os.path.exists('db') == False:
                os.mkdir('db')
            DataStorage.defaultStorage = DataStorage(datetime.now().strftime('%Y%m%d') + ".db")
        return DataStorage.defaultStorage

    def listDBs():
        for file in os.listdir('./db/'):
            print(file)

    def __init__(self,dbname):
        self.connection = sl.connect('./db/' + dbname)
        self.connection.row_factory = sl.Row
    '''
    Types:
    NULL. The value is a NULL value.
    INTEGER. The value is a signed integer, stored in 1, 2, 3, 4, 6, or 8 bytes depending on the magnitude of the value.
    REAL. The value is a floating point value, stored as an 8-byte IEEE floating point number.
    TEXT. The value is a text string, stored using the database encoding (UTF-8, UTF-16BE or UTF-16LE).
    BLOB. The value is a blob of data, stored exactly as it was input.
    '''
    def schemaCreate(self,name,cols,attrs):
        colStrs = []
        index = 0
        for col in cols:
            colStrs.append(str.format('{0} {1}',col,attrs[index]))
            index = index + 1
        spliter = ','
        sql = str.format('create table if not exists {0} ({1})',name,spliter.join(colStrs))
        cur = self.connection.cursor()
        cur.execute(sql)
        self.connection.commit()

    def query(self,sqlBuilder):
        cur = self.connection.cursor()
        cur.execute(sqlBuilder.build())
        return DataStorageResult(cur)
    def execute(self,sqlBuilder):
        cur = self.connection.cursor()
        cur.execute(sqlBuilder.build(),sqlBuilder.values)
        self.connection.commit()

if __name__ == "__main__":
    print("load from main")
    dataStorage = DataStorage('test.db')
    dataStorage.execute(SqlBuilder().insert('http',['method','url'],(b'POST','http://url')))
    builder = SqlBuilder().select('http',[]).where()
    result = dataStorage.query(builder)
    print(result.all())
    print(dataStorage.schemaCreate('http',['id','method','col2'],['INTEGER PRIMARY KEY ASC',DataStorage.DataTypeText,DataStorage.DataTypeText]))
