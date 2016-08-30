#!/usr/local/bin/python3

import subprocess

# exec command line & return the result
def exec_wait(command_line):
    p = subprocess.Popen(command_line, shell=True, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
    p.wait()

def exec_ret(command_line):
    p = subprocess.Popen(command_line, shell=True, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
    lines = p.stdout.read().decode('utf-8')
    return lines

def exec_ret_wait(command_line,wait_secs):
    p = subprocess.Popen(command_line, shell=True, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
    p.wait(wait_secs)
    return p.stdout.read().decode('utf-8')