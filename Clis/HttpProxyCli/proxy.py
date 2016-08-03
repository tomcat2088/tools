from twisted.web import proxy, http
from twisted.internet import reactor
from twisted.internet import protocol
from datetime import datetime
import logger
import sys

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
        reactor.listenTCP(self.port, ProxyFactory(self.host,self.port))
        reactor.run()
    def stop(self):
        logger.info("Proxy Stop On " + self.host + ":" + str(self.port))
        reactor.stop()

class DebugHttpClientProtocol(protocol.Protocol):
    def __init__(self, serverTransport,packetID):
        self.serverTransport = serverTransport
        self.packetID = packetID

    def sendMessage(self, data):
        logger.info("Client Write Data." + str(data,"utf-8"))
        self.transport.write(data)

    def dataReceived(self, data):
        logger.info("Client Recv Data.")
        self.data = data
        HttpProxy.shared().didRecvResponse(data,self.packetID)
        self.transport.loseConnection()

    def connectionLost(self, reason):
        logger.info("Client Lost Connection.")
        self.serverTransport.write(self.data)
        self.serverTransport.loseConnection()

class DebugHttpServerProtocol(protocol.Protocol):
    def dataReceived(self, data):
        if HttpProxy.shared().packetCount() > 5 :
            return
        self.data = data
        packetID = HttpProxy.shared().didRecvRequest(data)
        client = protocol.ClientCreator(reactor, DebugHttpClientProtocol, self.transport,packetID)
        print(dir(client))
        print(dir(self.factory))
        d = client.connectTCP(self.factory.targetHost, self.factory.targetPort)
        d.addCallback(self.forwardToClient, client)

    def forwardToClient(self, client, data):
        logger.info("Forward to client.")
        client.sendMessage(self.data)

class ProxyFactory(protocol.ServerFactory):
    protocol = DebugHttpServerProtocol

    def __init__(self, targetHost, targetPort):
        self.targetHost = targetHost
        self.targetPort = targetPort

def createProxy(callback):
    if HttpProxy.shared() is None:
        _sharedProxy = HttpProxy('127.0.0.1',9999,callback)
        HttpProxy.setShared(_sharedProxy)
    return _sharedProxy
