import logger
from datetime import datetime
from data_storage import *
import json
import packet_log_config

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
        for field in packet_log_config.logFields:
            logStr = packet_log_config.logStr(field,eval(str.format("self.{0}",field)))
            logStrs.append(logStr)
        logInfo = " ".join(logStrs)
        if packet_log_config.canBeShow(logInfo) == False:
            return
        print(" ".join(logStrs))
    def save(self):
        self.url = 'http://'+self.requestHeaders['host'] + str(self.url,'utf-8')
        self.method = str(self.method,'utf-8')

        dataStorage = DataStorage.default()
        tableName = 'http_traffics'
        cols = ['id','method','url','req_time','req_headers','req_data','resp_time','resp_headers','resp_data']
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

        insertCols = ['method','url','req_time','req_headers','req_data','resp_time','resp_headers','resp_data']
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

class PacketsManager:
    packets = dict()
    def addPacket():
        packet = HttpPacket()
        PacketsManager.packets[packet.id] = packet
        return packet
