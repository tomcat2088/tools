#!/usr/local/bin/python3

import sys
import getopt
import simulator
import crlogger

usage = '''Usage: {0} [options] <app bundle id>

Run specific App on simulator & collect the crashreport

Options:
  -h, --help                  show this help message and exit
  --version                   show version
  -u, --udid                  use simulator with udid
  -v, --verbose               enable verbose log output
'''

def show_usage():
    print(usage.format(sys.argv[0]))

def show_version():
    print('0.0.1')

def main(argv):
    try:
        opts, args = getopt.getopt(argv,"hu:v",["help","version","udid=","verbose"])
    except getopt.GetoptError:
        show_usage()
        sys.exit(2)

    udid = ''
    for opt, arg in opts:
        if opt in ['-h','--help']:
            show_usage()
        if opt in ['-v','--verbose']:
            crlogger.logger.enable()
        if opt in ['--version']:
            show_version()
        if opt in ['-u','--udid']:
            udid = arg


    if udid != '':
        print('running with udid : {0}'.format(udid))
    else:
        print('select simulator:')
        index = 1
        devices = simulator.list_devices()
        for device in devices:
            print('{0}: {1}'.format(index,device.debug_description()))
            index = index + 1
        result = input('>> ')
        select_device_index = int(result) - 1
        if select_device_index >=0 and select_device_index < len(devices):
            print('select device {0}'.format(devices[select_device_index].debug_description()))
            simulator.run_app(devices[select_device_index].udid,'com.dx168.epmyg')
            simulator.run_app_repeat(devices[select_device_index].udid,'com.dx168.epmyg',4,2)

if __name__ == "__main__":
    main(sys.argv[1:])