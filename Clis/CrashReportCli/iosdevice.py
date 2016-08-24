#!/usr/local/bin/python3
# coding: utf-8

from util import *
import json
import io,os
import time
import re
import datetime

class IOSDevice():
    def __init__(self,name,udid):
        self.name = name
        self.udid = udid

    def debug_description(self):
        return '{0} {1}'.format(self.name,self.udid)

def list_devices():
    result = exec_ret_wait('instruments -s devices',4)
    devices_lines = result.split('\n')
    simulators = []
    for line in devices_lines:
        ret = re.match(r'(.*)\[(.*)\]',line)
        if ret:
            name = ret.group(1)
            udid = ret.group(2)
            simulators.append(IOSDevice(name, udid))
    return simulators

def list_crash_report(simulator_name,app_bundle_name):
    crash_dir = os.path.expanduser('~/Library/Logs/DiagnosticReports')
    print(os.listdir(crash_dir))

def run_app(device_id,app_bundle_name):
    print('[{0}] Launch at {1}'.format(app_bundle_name,datetime.datetime.now().strftime('%H:%M:%S:%s')))
    automation_template_path = '/Applications/Xcode.app/Contents/Applications/Instruments.app/Contents/PlugIns/AutomationInstrument.xrplugin/Contents/Resources/Automation.tracetemplate'
    default_uia_file = 'automation.js'
    output_path = '/tmp/traces/'
    if os.path.exists(output_path) == False:
        os.mkdir(output_path)
    trace_file_name = datetime.datetime.now().strftime('%Y-%m-%d-%H:%M:%S') + '.trace'
    output_path = os.path.join(output_path,trace_file_name)
    print('Save trace to ' + output_path)
    command = 'instruments -w {0} -t {1} -D {4} {2} -e UIASCRIPT {3} '.format(device_id,automation_template_path,app_bundle_name,default_uia_file,output_path)
    ret = exec_wait(command)
    print('[{0}] Exit at {1}'.format(app_bundle_name,datetime.datetime.now().strftime('%H:%M:%S:%s')))

def run_app_repeat(device_id,app_bundle_name,launch_count,kill_delay):#kill_delay单位是s
    run_count = 1
    while launch_count > 0 or launch_count < 0:
        print('Run #{0}'.format(run_count))
        launch_count = launch_count - 1
        run_app(device_id,app_bundle_name)
        time.sleep(kill_delay)
        run_count = run_count + 1



if __name__ == '__main__':
    print('list devices')
    sims = list_devices()
    for sim in sims:
        print(sim.debug_description())
