#!/usr/bin/python
from jinja2 import Template
import sys

server_name = '127.0.0.1'
server_port = '8000'
document_root = '/usr/local/'

def find_nginx_conf():
	

def gen_server_config():
	with open("php.template", 'r') as file:
		content = file.read();
		template = Template(content)
		print(template.render(server_name = server_name,server_port = server_port,document_root = document_root))

usage = 'Usage:'+sys.argv[0] + ' server_name server_port document_root'

if len(sys.argv) <= 4:
	print(usage)
	gen_server_config()
else:
	server_name = sys.argv[1]
	server_port = sys.argv[2]
	document_root = sys.argv[3]
	gen_server_config()