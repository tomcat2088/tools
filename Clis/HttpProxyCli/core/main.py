#!/usr/local/bin/python3
import http_proxy
import sys
import packet_log_config
import getopt
from packets_manager import HttpPacket
from data_storage import DataStorage

def main(argv):
    address = '127.0.0.1'
    port = 9999
    queryDB = ""
    queryFields = []
    usage = str.format('{0} -i <ip address> -p <port> -f <filter> -e <complex filter> -b <select db> -q <query fields> -l <list all dbs>',sys.argv[0])
    try:
        opts, args = getopt.getopt(argv,"hi:p:f:e:b:q:l",["help","filter=","address","port","complexFilter","listdb","queryFields","listAllDB"])
    except getopt.GetoptError:
        print(usage)
        sys.exit(2)
    for opt, arg in opts:
        if opt == '-h':
            print(usage)
            sys.exit()
        elif opt == "-i":
            address = arg
        elif opt == "-p":
            port = int(arg)
        elif opt in ("-f", "--filter"):
            packet_log_config.setFilter(arg)
        elif opt in ("-e"):
            packet_log_config.setFilter(parseComplexFilter(arg))
        elif opt in ("-b"):
            queryDB = arg
        elif opt in ("-q"):
            queryFields = arg.split(",")
        elif opt in ("-l"):
            DataStorage.listDBs()
            sys.exit()
    if len(queryFields) <= 0:
        proxy_instance = http_proxy.HttpProxy(address,port)
        proxy_instance.start()
    else:
        HttpPacket.query(queryFields,queryDB)

def parseComplexFilter(rawFilter):
    filterDict = dict()
    filterAssign = rawFilter.split(",")
    for assign in filterAssign:
        pair = assign.split("=")
        if len(pair) == 2:
            filterDict[pair[0]] = pair[1]
    return filterDict

if __name__ == "__main__":
    main(sys.argv[1:])
