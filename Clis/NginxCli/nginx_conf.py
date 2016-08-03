import subprocess
import re
from pathlib import Path
import os

nginx_conf_path = None

def check_nginx_conf():
	print("Check environment ...")
	prefix = '--conf-path='
	conf_file = 'nginx.conf'
	p = subprocess.Popen('nginx -V', shell=True, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
	lines = p.stdout.read().decode('utf-8')
	regex_str = '--conf-path([a-zA-Z=//.]*)'
	m = re.search(regex_str,lines)
	if m:
		path = m.group(0)[len(prefix):]
		global nginx_conf_path
		nginx_conf_path = Path(path)
		fix_conf_file(path)
		conf_dir = path[:len(path) - len(conf_file)]
		print('Info: nginx.conf path is :' + path)
		return check_vhost(conf_dir)
	else:
		print("Error: nginx may not installed.")

def show_nginx_conf():
	global nginx_conf_path
	if nginx_conf_path:
		print(nginx_conf_path.read_text())

def fix_conf_file(conf_file_path):
	content = Path(conf_file_path).read_text()
	if content.find('include vhosts') >= 0:
		print("Info: nginx.conf pass validation.")
	else:
		print('Warning: nginx.conf need <include vhosts/*>,fixing...')
		with open(str(conf_file_path),'w+') as file:
			right_index = content.rfind('}')
			content = content[0:right_index]
			content = content+'include vhosts/*; \n}'
			file.write(content)

def check_vhost(conf_dir):
	conf_dir_path = Path(conf_dir)
	vhost_path = conf_dir_path / 'vhosts'
	if vhost_path.exists():
		print('Info: vhosts exists.')
	else:
		print('Error: vhosts not exists , creating ...')
		vhost_path.mkdir()
	return vhost_path

def list_servers(vhosts_path):
	print('You have following servers:')
	for x in os.listdir(str(vhosts_path)):
		print(x)

def create_server(name,port,conf_content,vhost_path):
	if vhost_path:
		conf_path = vhost_path / (name + "_" + port + '.conf')
		print(conf_path)
		if conf_path.exists():
			print('Server is already exists!!!')
		else:
			conf_path.touch()
			conf_path.write_text(conf_content)

def remove_server(name,vhost_path):
	if vhost_path:
		conf_path = vhost_path / (name + '.conf')
		print(conf_path)
		if conf_path.exists() == False:
			print('Server is not exists!!!')
		else:
			conf_path.unlink()
			print('{0} remove completed.'.format(name))