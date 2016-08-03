#!/usr/local/bin/python3
import http_proxy

def callback():
    print("callback is called")

proxy_instance = http_proxy.createProxy(callback)
proxy_instance.start()
