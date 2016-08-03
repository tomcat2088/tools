from twisted.internet import reactor
from twisted.web.client import Agent
from twisted.web.http_headers import Headers

agent = Agent(reactor)
body = "hello, world"
d = agent.request(
    b'GET',
    b'http://www.baidu.com')

def cbResponse(ignored):
    print('Response received')
d.addCallback(cbResponse)

def cbShutdown(ignored):
    print('Shut down')
    reactor.stop()
d.addBoth(cbShutdown)

reactor.run()
