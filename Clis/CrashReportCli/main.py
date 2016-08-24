#!/usr/local/bin/python3

import sys
import getopt
import iosdevice
import crlogger

usage = '''Usage: {0} [options] <action name> arguments

Run specific App on iDevice(iPhone|Simulator) & collect the crashreport

Options:
    -h, --help                  show this help message and exit
    --version                   show version
    -u, --udid                  use device with udid
    -v, --verbose               enable verbose log output

Actions:
    ls                                          list devices
    run <app bundle id> <repeat count> <delay>  run app on device.if repeat count < 0,run forever

'''


def show_usage():
	print(usage.format(sys.argv[0]))
	exit(2)

def show_version():
	print('0.0.1')


def main(argv):
	try:
		opts, args = getopt.getopt(argv, "hu:v", ["help", "version", "udid=", "verbose"])
	except getopt.GetoptError:
		show_usage()
		sys.exit(2)

	udid = ''
	option_last_index = 0
	for opt, arg in opts:
		if opt in ['-h', '--help']:
			show_usage()
		if opt in ['-v', '--verbose']:
			crlogger.logger.enable()
		if opt in ['--version']:
			show_version()
		if opt in ['-u', '--udid']:
			udid = arg
		if opt != '':
			option_last_index = option_last_index + 1
		if arg != '':
			option_last_index = option_last_index + 1

	app_bundle_id = ''
	action = ''
	repeat_count = 0
	delay = 2
	if option_last_index < len(argv):
		action = argv[option_last_index]
	if action == 'run':
		if option_last_index + 1 < len(argv):
			app_bundle_id = argv[option_last_index + 1]
		if app_bundle_id == '':
			show_usage()
		if option_last_index + 2 < len(argv):
			repeat_count = int(argv[option_last_index + 2])
		if option_last_index + 3 < len(argv):
			delay = int(argv[option_last_index + 3])
		if udid != '':
			print('Running with device udid : {0}'.format(udid))
		else:
			print('Select device:')
			index = 1
			devices = iosdevice.list_devices()
			for device in devices:
				print('{0}: {1}'.format(index, device.debug_description()))
				index = index + 1
			result = input('>> ')
			select_device_index = int(result) - 1
			if select_device_index >= 0 and select_device_index < len(devices):
				print('Select device {0}'.format(devices[select_device_index].debug_description()))
				udid = devices[select_device_index].udid
			else:
				print('invalid device')
				exit(2)

		if repeat_count != 0:
			iosdevice.run_app_repeat(udid, app_bundle_id, repeat_count, delay)
		else:
			iosdevice.run_app(udid, app_bundle_id)
	elif action == 'ls':
		devices = iosdevice.list_devices()
		for device in devices:
			print(device.debug_description())
	else:
		show_usage()

if __name__ == "__main__":
	main(sys.argv[1:])
