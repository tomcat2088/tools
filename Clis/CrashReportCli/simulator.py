#!/usr/local/bin/python3

from util import *
import json
import io,os

# collect crash report for iOS simulator

class Simulator():
    def __init__(self,os,dict):
        self.os = os
        self.name = dict['name']
        self.udid = dict['udid']

    def debug_description(self):
        return '{0} {1} {2}'.format(self.os,self.name,self.udid)

def list_simulator():
    devices_json = exec_ret('xcrun simctl list -j devices')
    json_dict = json.loads(devices_json)
    simulators = []
    for os in json_dict['devices']:
        for device in json_dict['devices'][os]:
            simulators.append(Simulator(os,device))
    return simulators

def list_crash_report(simulator_name,app_bundle_name):
    crash_dir = os.path.expanduser('~/Library/Logs/DiagnosticReports')
    print(os.listdir(crash_dir))


if __name__ == '__main__':
    sims = list_simulator()
    for sim in sims:
        print(sim.debug_description())
    list_crash_report('1313','131')
