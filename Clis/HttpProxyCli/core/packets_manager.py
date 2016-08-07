import logger
from datetime import datetime
from data_storage import *
import json

class HttpPacket:
    def __init__(self):
        now = datetime.utcnow()
        utcsecs = (now - datetime(1970, 1, 1)).total_seconds()
        self.id = str(int(utcsecs * 1000000))
        self.requestHeaders = {}
        self.requestData = b''
        self.responseHeaders = {}
        self.responseData = b''
    def log(self):
        output = str.format('{0} {1} {2} {3}...',str(datetime.today()),self.method,self.url,str(self.responseData,'utf-8')[0:20])
        print(output)
    def save(self):
        self.url = 'http://'+self.requestHeaders['host'] + str(self.url,'utf-8')
        self.method = str(self.method,'utf-8')

        dataStorage = DataStorage.default()
        tableName = 'http_traffics'
        cols = ['id','method','url','req_headers','req_data','resp_headers','resp_data']
        colsTypes = ['INTEGER PRIMARY KEY ASC',DataStorage.DataTypeText,DataStorage.DataTypeText,DataStorage.DataTypeText,DataStorage.DataTypeText,DataStorage.DataTypeText,DataStorage.DataTypeText]
        dataStorage.schemaCreate(tableName,cols,colsTypes)

        insertCols = ['method','url','req_headers','req_data','resp_headers','resp_data']
        values = [self.method,self.url,json.dumps(self.requestHeaders),memoryview(self.requestData),json.dumps(self.responseHeaders),memoryview(self.responseData)]
        dataStorage.execute(SqlBuilder().insert(tableName,insertCols,values))

        self.log()

class PacketsManager:
    packets = dict()
    def addPacket():
        packet = HttpPacket()
        PacketsManager.packets[packet.id] = packet
        return packet