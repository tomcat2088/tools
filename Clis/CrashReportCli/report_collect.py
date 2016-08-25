import os
from shutil import copyfile
import datetime

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
	if dest_path and len(dest_path) > 0 and os.path.exists(dest_path):
		for file in filter_files:
			src_file = os.path.join(crash_dir,file)
			dest_file = os.path.join(dest_path,file)
			copyfile(src_file,dest_file)
	return filter_files

def collect_report_for_simulator(app_name,dest_path,time_begin=None,time_end=None):
	crash_dir = os.path.expanduser('~/Library/Logs/DiagnosticReports')
	collect_report_in_dir(crash_dir,app_name,dest_path,time_begin,time_end)

if __name__ == '__main__':
	begin_time = datetime.datetime.now() - datetime.timedelta(days=5)
	end_time = datetime.datetime.now()
	files = collect_report_for_simulator('Demo1','/tmp/crashes/',begin_time,end_time)
	print(files)