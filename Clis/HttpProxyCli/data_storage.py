import sqlite3 as sl
import logger

class SqlBuilder:
    def __init__(self):
        self.sqlLists = []
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
        sql = str.format('insert into {0} ({1}) values({2})',tableName,spliter.join(cols),spliter.join(processedVals))
        self.sqlLists.append(sql)
        return self

    def where(self,conditionDict):
        sql = "where "
        for key in conditionDict:
            conditionStr = str.format('{0}\'{1}\' ',key,conditionDict[key])
            sql += conditionStr
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
    def __init__(self,dbname):
        self.connection = sl.connect(dbname)
    def query(self,sqlBuilder):
        cur = self.connection.cursor()
        cur.execute(sqlBuilder.build())
        return DataStorageResult(cur)
    def execute(self,sqlBuilder):
        cur = self.connection.cursor()
        cur.execute(sqlBuilder.build())
        return DataStorageResult(cur)

if __name__ == "__main__":
    print("load from main")
    dataStorage = DataStorage('test.db')
    print(SqlBuilder().insert('http',['method'],['POST']).build())
    builder = SqlBuilder().select('http',[]).where({'url=':'http://www.baidu.com'})
    result = dataStorage.query(builder)
