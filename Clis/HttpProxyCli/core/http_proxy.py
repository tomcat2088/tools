from twisted.python import log
from twisted.web import http, proxy
from twisted.internet import reactor
from datetime import datetime
from packets_manager import PacketsManager
import logger
from io import BytesIO

class ProxyClient(proxy.ProxyClient):

    def __init__(self, command, rest, version, headers, data, father):
        proxy.ProxyClient.__init__(self, command, rest, version, headers, data, father)
        self.packet = PacketsManager.addPacket()
        self.packet.method = command
        self.packet.url = rest
        self.packet.requestTime = datetime.now()
        self.packet.requestHeaders = self.parseBinaryDict(headers)
        self.packet.requestData = data
        self.packet.responseData = BytesIO()
    def handleResponsePart(self, buffer):
        self.packet.responseData.write(buffer)
        proxy.ProxyClient.handleResponsePart(self,buffer)
    def handleResponseEnd(self):
        if not self._finished:
            self.packet.responseTime = datetime.now()
            self.packet.responseData.seek(0)
            self.packet.responseData = self.packet.responseData.read()
            self.packet.responseHeaders = self.parseBinaryDict(self.father.responseHeaders._rawHeaders)
            self.packet.save()
            proxy.ProxyClient.handleResponseEnd(self)

    def parseBinaryDict(self,binaryDict):
        strDict = dict()
        for key in binaryDict:
            if type(binaryDict[key]) is list:
                listStr = ""
                for item in binaryDict[key]:
                    listStr += str(item,'utf-8')
                strDict[str(key,'utf-8')] = listStr
            elif type(binaryDict[key]) is bytes:
                strDict[str(key,'utf-8')] = str(binaryDict[key],'utf-8')
        return strDict


class ProxyClientFactory(proxy.ProxyClientFactory):
    protocol = ProxyClient

class ProxyRequest(proxy.ProxyRequest):
    protocols = dict()
    ports = dict()
    protocols[b'http'] = ProxyClientFactory
    ports[b'http'] = 80

class Proxy(proxy.Proxy):
    requestFactory = ProxyRequest

class ProxyFactory(http.HTTPFactory):
    protocol = Proxy

class HttpProxy():
    def __init__(self,host,port):
        self.isStarted = False
        self.httpPackets = {};
        self.host = host
        self.port = port

    def start(self):
        if self.isStarted == True:
            return
        logger.info("Proxy Start On " + self.host + ":" + str(self.port))
        reactor.listenTCP(self.port, ProxyFactory())
        reactor.run()
        self.isStarted = True
    def stop(self):
        if self.isStarted == False:
            return
        logger.info("Proxy Stop On " + self.host + ":" + str(self.port))
        reactor.stop()
        self.isStarted = False
