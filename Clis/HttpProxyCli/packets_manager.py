import logger

class HttpPacket:
    def __init__(self):
        now = datetime.utcnow()
        utcsecs = (now - datetime(1970, 1, 1)).total_seconds()
        self.id = str(utcsecs);
    def setRequestData(self,requestData):
        self.requestData = requestData
    def setResponseData(self,responseData):
        self.responseData = responseData

class PacketsManager:
    packets = dict()
    def addPacket():
        packet = HttpPacket()
        packets[packet.id] = packet
        logger.info("packet add:" + packet.id)
        return packet.id
    def setPacketResponse(id,responseData):
        packet = packets[id]
        if packet:
            packet.setResponseData(responseData)
            logger.info("packet response:" + packet.id)
