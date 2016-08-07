#!/usr/local/bin/python3

import os
import sys
import subprocess

def showUsage():
    print(str.format('Usage: {0} action params',sys.argv[0]))
    print(str.format('{0} -e service host port',sys.argv[0]))
    print(str.format('{0} -s service',sys.argv[0]))
    print(str.format('{0} -l',sys.argv[0]))

def actionFunc(actionName):
    actionMap = dict()
    actionMap['-e'] = enableProxy
    actionMap['-l'] = listNetworkServices
    actionMap['-s'] = disableProxy
    return actionMap[actionName]

def listNetworkServices(args):
    p = subprocess.Popen('networksetup -listallnetworkservices', shell=True, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
    lines = p.stdout.read().decode('utf-8')
    services = []
    for line in lines.split('\n')[1:]:
        if line != '':
            print(line)
            services.append(line)
    return services

def enableProxy(args):#networkService,host,port
    commandLine = str.format('sudo networksetup -setwebproxy {0} {1} {2} off',args[0],args[1],args[2])
    print('call ' + commandLine)
    os.system(commandLine)

def disableProxy(args):
    commandLine = str.format('sudo networksetup -setwebproxystate {0} off',args[0])
    print('call ' + commandLine)
    os.system(commandLine)

def main():
    action = sys.argv[1]
    actionFunc(action)(sys.argv[2:])

if len(sys.argv) <= 1:
    showUsage()
    exit(0)
main()
