#!/usr/local/bin/python3
import http_proxy
import sys
import packet_log_config
import getopt

def main(argv):
    address = '127.0.0.1'
    port = 9999
    usage = str.format('{0} -i <ip address> -p <port> -f <filter>',sys.argv[0])
    try:
        opts, args = getopt.getopt(argv,"hi:p:f:",["help","filter=","address","port"])
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

    proxy_instance = http_proxy.HttpProxy(address,port)
    proxy_instance.start()

if __name__ == "__main__":
    main(sys.argv[1:])
