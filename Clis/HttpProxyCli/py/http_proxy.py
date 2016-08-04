from twisted.python import log
from twisted.web import http, proxy
from twisted.internet import reactor
from datetime import datetime
from packets_manager import PacketsManager
import logger

class ProxyClient(proxy.ProxyClient):

    def __init__(self, command, rest, version, headers, data, father):
        proxy.ProxyClient.__init__(self, command, rest, version, headers, data, father)
        self.packet = PacketsManager.addPacket()
        self.packet.method = command
        self.packet.url = rest
        self.packet.requestHeaders = headers
        self.packet.requestData = data
    def handleResponseEnd(self):
        self.packet.responseHeaders = self.father.responseHeaders
        proxy.ProxyClient.handleResponseEnd(self)
        self.packet.log()


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
    def __init__(self,host,port,dataCallback):
        self.isStarted = False
        self.httpPackets = {};
        self.host = host
        self.port = port
        self.dataCallback = dataCallback

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
