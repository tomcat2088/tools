from twisted.python import log
from twisted.web import http, proxy
from twisted.internet import reactor
import logger
from datetime import datetime
from packets_manager import PacketsManager

class ProxyClient(proxy.ProxyClient):

    def __init__(self, command, rest, version, headers, data, father):
        proxy.ProxyClient.__init__(self, command, rest, version, headers, data, father)
        self.packetID = PacketsManager.addPacket()

    def handleResponsePart(self, buffer):
        proxy.ProxyClient.handleResponsePart(self, buffer)
        PacketsManager.setPacketResponse(self.packetID,buffer)

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
    isStarted = False
    def __init__(self,host,port,dataCallback):
        self.httpPackets = {};
        self.host = host
        self.port = port
        self.dataCallback = dataCallback

    def start(self):
        if isStarted == True:
            return
        logger.info("Proxy Start On " + self.host + ":" + str(self.port))
        reactor.listenTCP(self.port, ProxyFactory())
        reactor.run()
        isStarted = True
    def stop(self):
        if isStarted == False:
            return
        logger.info("Proxy Stop On " + self.host + ":" + str(self.port))
        reactor.stop()
        isStarted

def createProxy(callback):
    if HttpProxy.shared() is None:
        _sharedProxy = HttpProxy('127.0.0.1',9999,callback)
        HttpProxy.setShared(_sharedProxy)
    return _sharedProxy
