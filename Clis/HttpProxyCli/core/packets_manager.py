import logger
from datetime import datetime
from data_storage import *
import json
import packet_log_config
from termcolor import colored

class HttpPacket:
    def __init__(self):
        now = datetime.utcnow()
        utcsecs = (now - datetime(1970, 1, 1)).total_seconds()
        self.id = str(int(utcsecs * 1000000))
        self.requestTime = 0
        self.responseTime = 0
        self.requestHeaders = {}
        self.requestData = b''
        self.responseHeaders = {}
        self.responseData = b''
    def log(self):
        logStrs = []
        matchFilter = True
        for field in packet_log_config.logFields:
            logStr = packet_log_config.logStr(field,eval(str.format("self.{0}",field)))
            logStrs.append(logStr)
            if packet_log_config.isMatchField() and packet_log_config.fieldMatch(logStr,field) == False:
                matchFilter = False
        logInfo = " ".join(logStrs)
        if packet_log_config.isMatchField() == False:
            matchFilter = packet_log_config.allTextMatch(logInfo)
        if matchFilter:
            print(" ".join(logStrs))
    def save(self):
        # id
        # method
        # url
        # requestTime
        # requestHeaders
        # requestData
        # responseTime
        # responseHeaders
        # responseData
        self.url = 'http://'+self.requestHeaders['host'] + str(self.url,'utf-8')
        self.method = str(self.method,'utf-8')

        dataStorage = DataStorage.default()
        tableName = 'http_traffics'
        cols = ['id','method','url','requestTime','requestHeaders','requestData','responseTime','responseHeaders','responseData']
        colsTypes = ['INTEGER PRIMARY KEY ASC',
        DataStorage.DataTypeText,
        DataStorage.DataTypeText,
        DataStorage.DataTypeInt,
        DataStorage.DataTypeText,
        DataStorage.DataTypeText,
        DataStorage.DataTypeInt,
        DataStorage.DataTypeText,
        DataStorage.DataTypeText]

        dataStorage.schemaCreate(tableName,cols,colsTypes)

        insertCols = ['method','url','requestTime','requestHeaders','requestData','responseTime','responseHeaders','responseData']
        values = [self.method,
        self.url,
        self.requestTime,
        json.dumps(self.requestHeaders),
        memoryview(self.requestData),
        self.responseTime,
        json.dumps(self.responseHeaders),
        memoryview(self.responseData)]

        dataStorage.execute(SqlBuilder().insert(tableName,insertCols,values))

        self.log()

    def query(fields,db):
        tableName = 'http_traffics'
        dataStorage = DataStorage.default()
        if db != "":
            dataStorage = DataStorage(db)
        whereDict = dict()
        for key in fields.keys():
            if len(fields[key]) > 0:
                whereDict[key + " like "] = fields[key]
        builder = SqlBuilder().select(tableName,list(fields.keys())).where(whereDict)
        rowNum = 1
        for row in dataStorage.query(builder).all():
            print('=' * 30 + ' Row <' + str(rowNum) + '> ' + '=' * 30)
            if len(fields) == 0:
                fields = row.keys()
            for field in fields:
                logStr = ''
                if type(row[field]) is bytes:
                    logStr = str.format('[{0}]\n{1}',colored(field,'cyan'),colored(str(row[field],'utf-8'),'white'))
                else:
                    logStr = str.format('[{0}]\n{1}',colored(field,'cyan'),colored(str(row[field]),'white'))
                print(logStr)
            rowNum += 1

class PacketsManager:
    packets = dict()
    def addPacket():
        packet = HttpPacket()
        PacketsManager.packets[packet.id] = packet
        return packet
