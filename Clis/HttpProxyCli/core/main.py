#!/usr/local/bin/python3
import http_proxy
import sys
import packet_log_config
import getopt

def main(argv):
    usage = str.format('{0} -f <filter>',sys.argv[0])
    try:
        opts, args = getopt.getopt(argv,"hf:",["help","filter="])
    except getopt.GetoptError:
        print(usage)
        sys.exit(2)
    for opt, arg in opts:
        if opt == '-h':
            print(usage)
            sys.exit()
        elif opt in ("-f", "--filter"):
            packet_log_config.setFilter(arg)

    proxy_instance = http_proxy.HttpProxy('127.0.0.1',9999)
    proxy_instance.start()

if __name__ == "__main__":
    main(sys.argv[1:])
