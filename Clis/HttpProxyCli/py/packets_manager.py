import logger
from datetime import datetime

class HttpPacket:
    def __init__(self):
        now = datetime.utcnow()
        utcsecs = (now - datetime(1970, 1, 1)).total_seconds()
        self.id = str(int(utcsecs * 1000000))
        self.requestHeaders = {}
        self.requestData = ""
        self.responseHeaders = {}
        self.responseData = ""
    def log(self):
        output = str.format('{0} {1} {2}',str(self.id),str(self.method,'utf-8'),str(self.url,'utf-8'))
        print(output)
        # print(str(self.requestHeaders))
        # print(str(self.requestData))
        print(str(self.responseHeaders))
        # print(str(self.responseData))
    def save(self):
        pass

class PacketsManager:
    packets = dict()
    def addPacket():
        packet = HttpPacket()
        PacketsManager.packets[packet.id] = packet
        return packet
