import logging


class Logger():
    def __init__(self):
        self.logger = None
    def info(self,info):
        if self.logger != None:
            self.logger.info(info)

    def enable(self):
        if self.logger != None:
            return
        ch = logging.StreamHandler()
        ch.setLevel(logging.INFO)
        self.logger = logging.getLogger('logger')
        self.logger.setLevel(logging.INFO)
        self.logger.addHandler(ch)

    def disable(self):
        if self.logger != None:
            self.logger = None

logger = Logger()