#!/usr/local/bin/python3

import sys
import subprocess
import _thread
import re
import time

#instruments -w 05069bf5ecf00c35e51f58fad353c70d5ae9fe59 -t /Applications/Xcode.app/Contents/Applications/Instruments.app/Contents/PlugIns/AutomationInstrument.xrplugin/Contents/Resources/Automation.tracetemplate com.dx168.epmyg -e UIASCRIPT ui.js

instruments_command_template = 'instruments -w {0} -t /Applications/Xcode.app/Contents/Applications/Instruments.app/Contents/PlugIns/AutomationInstrument.xrplugin/Contents/Resources/Automation.tracetemplate {1} -e UIASCRIPT {2}'
usage = 'usage: {0} device app_bundle_id automationfile'.format(sys.argv[0])

global lldb_process

def begin_automation(thread_name,delay):
    instruments_command = instruments_command_template.format(sys.argv[1],sys.argv[2],sys.argv[3])
    p = subprocess.Popen(instruments_command, shell=True, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
    lines = p.stdout.readlines()
    print(lines)

def attach_lldb(thread_name,pid):
    global lldb_process
    lldb_process = subprocess.Popen('lldb -p {0} -o {1}'.format(pid,'continue'), shell=True, stdout=subprocess.PIPE,stdin=subprocess.PIPE, stderr=subprocess.STDOUT)
    while True:
        line = lldb_process.stdout.readline()[:-1]
        print(line)

if __name__ == '__main__':
    if len(sys.argv) < 4:
        print(usage)
        exit(0)

    refresh_thread = _thread.start_new_thread(begin_automation,("refresh_thread",6))
    print('Wait for process start ... ')
    while True:
        p = subprocess.Popen('ps -ax | grep "epmyg.app/epmyg"', shell=True, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
        lines = p.stdout.read().decode('utf-8')
        print(lines)
        match = re.search('^([0-9]+)\s(?!tty)',lines)
        if match and len(match.group(1)) > 0:
            pid = match.group(1)
            print('PID Found : ' + pid)
            print('Attach lldb to PID ' + pid)
            _thread.start_new_thread(attach_lldb,("lldb_thread",pid))

            while True:
                command = input('>> ')
                if command == 'q':
                    exit(0)
                else:
                    global lldb_process
                    if lldb_process != None:
                        print('commu' + command)
                        out =  lldb_process.communicate(input=bytes(command + "\n",'utf-8'))
                        print(out)
        time.sleep(1)
