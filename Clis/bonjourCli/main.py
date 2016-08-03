#!/usr/local/bin/python3
import subprocess
import re
import _thread
import time
import os
from termcolor import colored

global services;
services = []

def add_service(service):
	global services;
	for item in services:
		if item == service:
			return
	services.append(service)

def refresh(thread_name,delay):
	while True:
		os.system('clear')
		print(colored("EPM Log Services:","white"))
		for item in services:
			print(colored("=>  http://" + item,'yellow'))
		time.sleep(delay)
		

def process_dns_sd_cli():
	p = subprocess.Popen('dns-sd -L "epm-remote-log" _http', shell=True, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
	while True:
		line = p.stdout.readline()[:-1]
		search_result = re.search('(?<=at )[0-9a-zA-Z:\-.]+',line.decode('utf-8'))
		if search_result:
			add_service(search_result.group(0))


refresh_thread = _thread.start_new_thread(refresh,("refresh_thread",6))

process_dns_sd_cli()
while True:
	pass