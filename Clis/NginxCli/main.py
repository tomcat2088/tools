#!/usr/local/bin/python3
from jinja2 import Template
import sys
import subprocess
from nginx_conf import *

server_name = '127.0.0.1'
server_port = '8000'
document_root = '/usr/local/'

def gen_server_config():
	with open("php.template", 'r') as file:
		content = file.read();
		template = Template(content)
		return (template.render(server_name = server_name,server_port = server_port,document_root = document_root))

# usage = 'Usage:'+sys.argv[0] + ' server_name server_port document_root'

# if len(sys.argv) <= 4:
# 	print(usage)
# 	gen_server_config()
# else:
# 	server_name = sys.argv[1]
# 	server_port = sys.argv[2]
# 	document_root = sys.argv[3]
# 	gen_server_config()

def validation():
	if len(server_name) > 0 and len(server_port) > 0 and len(document_root) > 0:
		return True
	return False

print("Welcome to Nginx Cli v1.0.0")
vhost_path = check_nginx_conf()
if vhost_path is None:
	print('Start Failed!!!')

while 1:
	word = input('>>');
	if word == 'q':
		break
	elif word == 'i':
		show_nginx_conf()
	elif word == 'ls':
		list_servers(vhost_path)
	elif word == 'create':
		server_name = input("Input server_name: ")
		server_port = input("Input server_port: ")
		document_root = input("Input www_root: ")
		if validation():
			content = gen_server_config()
			print("Preview:\n")
			print(content)
			choice = input("Want to use this? (yes | no): ")
			if choice == 'yes' or choice == 'y':
				create_server(server_name,server_port,content,vhost_path)
	elif word == 'rm':
		server_name = input("Input server_name: ")
		choice = input("Really want to remove this? (yes | no): ")
		if choice == 'yes' or choice == 'y':
			remove_server(server_name,vhost_path)
	elif word == 'reload':
		subprocess.call(['nginx','-s','stop'])
		subprocess.call(['nginx'])



