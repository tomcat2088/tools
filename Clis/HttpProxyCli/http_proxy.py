from twisted.python import log
from twisted.web import http, proxy
from twisted.internet import reactor
import logger
from datetime import datetime

class ProxyClient(proxy.ProxyClient):
    def setPacketID(self,packetID):
        print(str(self) + str(packetID))

    def handleHeader(self, key, value):
        # change response header here
        #print("Header: %s: %s" % (key, value))
        proxy.ProxyClient.handleHeader(self, key, value)

    def handleResponsePart(self, buffer):
        # change response part here
        #print("Content: %s" % (buffer))
        # make all content upper case
        proxy.ProxyClient.handleResponsePart(self, buffer.upper())

class ProxyClientFactory(proxy.ProxyClientFactory):
    protocol = ProxyClient

    def buildProtocol(self, addr):
        print(str(addr))
        return proxy.ProxyClientFactory.buildProtocol(self,addr)

class ProxyRequest(proxy.ProxyRequest):
    protocols = dict()
    protocols[b'http'] = ProxyClientFactory

    def requestReceived(self, command, path, version):
        #print(str(command))
        #print(str(path))
        packetID = HttpProxy.shared().didRecvRequest(None)
        proxy.ProxyRequest.requestReceived(self,command,path,version)

    def handleContentChunk(self, data):
        print(str(data))
        proxy.ProxyRequest.handleContentChunk(self,data)

class Proxy(proxy.Proxy):
    requestFactory = ProxyRequest

class ProxyFactory(http.HTTPFactory):
    protocol = Proxy

class HttpPacketBase:
    def __init__(self):
        now = datetime.utcnow()
        utcsecs = (now - datetime(1970, 1, 1)).total_seconds()
        self.id = str(utcsecs);
    def setRequestData(self,requestData):
        self.requestData = requestData
    def setResponseData(self,responseData):
        self.responseData = responseData

class HttpProxy():
    _sharedProxy = None
    def setShared(shared):
        HttpProxy._sharedProxy = shared

    def shared():
        return HttpProxy._sharedProxy

    def __init__(self,host,port,dataCallback):
        self.httpPackets = {};
        self.host = host
        self.port = port
        self.dataCallback = dataCallback

    def packetCount(self):
        return len(self.httpPackets)

    def didRecvRequest(self,requestData):
        packet = HttpPacketBase()
        logger.info("Request Recv. id => " + packet.id)
        self.httpPackets[packet.id] = packet
        return packet.id

    def didRecvResponse(self,responseData,id):
        packet = self.httpPackets[id]
        packet.responseData = responseData
        logger.info("Response Recv. id => " + packet.id)
        logger.info("Packet Finish. id => " + packet.id)

    def start(self):
        logger.info("Proxy Start On " + self.host + ":" + str(self.port))
        reactor.listenTCP(self.port, ProxyFactory())
        reactor.run()
    def stop(self):
        logger.info("Proxy Stop On " + self.host + ":" + str(self.port))
        reactor.stop()

def createProxy(callback):
    if HttpProxy.shared() is None:
        _sharedProxy = HttpProxy('127.0.0.1',9999,callback)
        HttpProxy.setShared(_sharedProxy)
    return _sharedProxy
