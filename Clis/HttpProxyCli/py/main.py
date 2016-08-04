#!/usr/local/bin/python3
import http_proxy

def callback():
    print("callback is called")

proxy_instance = http_proxy.HttpProxy('127.0.0.1',9999,callback)
proxy_instance.start()
