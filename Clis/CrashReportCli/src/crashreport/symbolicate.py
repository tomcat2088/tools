import json
import os
import re

from crashreport import symbol_collect
from crashreport import util
from crashreport.crlogger import *


def find_app_name(file):
    while True:
        line = file.readline()
        if len(line) == 0:
            return ''
        app_name_match = re.match(r'^Process:\s+(\w+)\s+\[', line)
        if app_name_match:
            app_name = app_name_match.group(1)
            return app_name

def process_crash(crash_file):
    logger.info('Process crash report at {0}'.format(crash_file))
    symbolicatecrash = '/Applications/Xcode.app/Contents/SharedFrameworks/DVTFoundation.framework/Versions/A/Resources/symbolicatecrash'
    # use symbolicatecrash to process system backtrace
    logger.info('Symbolicatecrash...')
    export_command = 'export DEVELOPER_DIR="/Applications/Xcode.app/Contents/Developer"'
    util.exec_wait('{0} && {1} {2} > {3}.tmp'.format(export_command,symbolicatecrash, crash_file, crash_file))
    logger.info('Symbolicatecrash complete.')
    file = open('{0}.tmp'.format(crash_file))
    app_name = find_app_name(file)
    file.seek(0)
    if app_name == '':
        print('App Name not found')
        exit(2)
    logger.info('App Name is {0}'.format(app_name))
    symbol_file = symbol_collect.find_match_symbol_or_app(app_name)
    if os.path.exists(symbol_file) == False:
        logger.info('No dSYM File Found!')
        exit(2)
    print('Find dSYM in {0}'.format(symbol_file))
    while True:
        line = file.readline()
        if len(line) == 0:
            break
        re_str = r'^\d+\s+(\w+)\s+(\w+)\s+(\w+)'
        ret = re.match(re_str,line)
        if ret:
            name = ret.group(1)
            if name == app_name:
                address = ret.group(2)
                base_address = ret.group(3)
                result = util.exec_ret('atos -arch arm64 -o "{0}" -l {1} {2}'.format(symbol_file, base_address, address))
                line = re.sub(r'\s+(\w+ \+ \w+)',r' {0}'.format(result),line)
                print(line,end="")
        else:
            print(line,end="")
    file.close()


if __name__ == '__main__':
    process_crash('/Users/ocean/Documents/crashes/epmyg.crash')