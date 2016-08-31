import datetime
import os
from shutil import copyfile

from crashreport import util


def crashes_tmp_dir(device_id):
	base_tmp_dir = '/tmp/crashes'
	if os.path.exists(base_tmp_dir) == False:
		os.mkdir(base_tmp_dir)
	device_crash_dir = os.path.join(base_tmp_dir,device_id)
	if os.path.exists(device_crash_dir) == False:
		os.mkdir(device_crash_dir)
	current_date_str = datetime.datetime.now().strftime('%Y-%m-%d_%H:%M:%S:%s')
	device_crash_session_dir = os.path.join(device_crash_dir,current_date_str)
	if os.path.exists(device_crash_session_dir) == False:
		os.mkdir(device_crash_session_dir)
	return device_crash_session_dir

def crashes_cache_dir(device_id):
	base_tmp_dir = '/tmp/crashes/cache'
	if os.path.exists(base_tmp_dir) == False:
		os.mkdir(base_tmp_dir)
	device_crash_dir = os.path.join(base_tmp_dir,device_id)
	if os.path.exists(device_crash_dir) == False:
		os.mkdir(device_crash_dir)
	return device_crash_dir

def collect_report_in_dir(crash_dir,app_name,dest_path,time_begin=None,time_end=None):
	files = os.listdir(crash_dir)
	filter_files = []
	for file in files:
		if file.startswith(app_name):
			if time_begin and time_end:
				src_file = os.path.join(crash_dir, file)
				time = os.stat(src_file).st_birthtime
				dtime = datetime.datetime.fromtimestamp(time)
				if dtime >= time_begin and dtime <= time_end:
					filter_files.append(file)
			else:
				filter_files.append(file)
	if dest_path and len(dest_path) > 0 and os.path.exists(dest_path):
		for file in filter_files:
			src_file = os.path.join(crash_dir,file)
			dest_file = os.path.join(dest_path,file)
			copyfile(src_file,dest_file)
		print('Crash reports move into:' + dest_path)
	return filter_files

def collect_report_for_simulator(app_name,time_begin=None,time_end=None,dest_path=None):
	crash_dir = os.path.expanduser('~/Library/Logs/DiagnosticReports')
	if dest_path == None:
		dest_path = crashes_tmp_dir('simulator')
	return collect_report_in_dir(crash_dir,app_name,dest_path,time_begin,time_end)

def current_device_id():
	# 暂时不处理多个设备连接的情况
	ret = util.exec_ret('idevice_id -l')
	devices = ret.split('\n')
	if len(devices) > 0:
		return devices[0]
	return ''

def collect_report_for_device(app_name,device_id,time_begin=None,time_end=None,dest_path=None):
	crash_dir = crashes_cache_dir(device_id)
	command = 'idevicecrashreport -u {0} {1}'.format(device_id,crash_dir)
	util.exec_wait(command)
	if dest_path == None:
		dest_path = crashes_tmp_dir(device_id)
	return collect_report_in_dir(crash_dir,app_name,dest_path,time_begin,time_end)

def collect_report(app_name,device_id,time_begin=None,time_end=None,dest_path=None):
	if device_id.find('-') >= 0:# simulator uuid
		collect_report_for_simulator(app_name,time_begin,time_end,dest_path)
	else:
		collect_report_for_device(app_name, device_id, time_begin, time_end, dest_path)

if __name__ == '__main__':
	begin_time = datetime.datetime.now() - datetime.timedelta(days=5)
	end_time = datetime.datetime.now()
	files = collect_report_for_simulator('epmyg',begin_time,end_time)
	print(files)

	device_id = current_device_id()
	if len(device_id) > 1:
		files = collect_report_for_device('CoreDumpDemo', device_id,begin_time, end_time)
		print(files)