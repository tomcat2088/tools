import io
import re
import debug_symbol_manager
import json
import os
import util

def process_crash(crash_file):
    symbolicatecrash = '/Applications/Xcode.app/Contents/SharedFrameworks/DVTFoundation.framework/Versions/A/Resources/symbolicatecrash'
    # use symbolicatecrash to process system backtrace
    util.exec_wait('{0} {1} > {2}.tmp'.format(symbolicatecrash,crash_file,crash_file))
    util.exec_wait('mv {1}.tmp {2}'.format(symbolicatecrash, crash_file, crash_file))

    file = open(crash_file)
    first_line = file.readline()
    info = json.loads(first_line)
    app_name = info['app_name']
    symbol_file = debug_symbol_manager.find_match_symbol_or_app(app_name)
    if os.path.exists(symbol_file) == False:
        print('No dSYM File Found!')
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
                result = util.exec_ret('atos -arch arm64 -o "{0}" -l {1} {2}'.format(symbol_file,base_address,address))
                line = re.sub(r'\s+(\w+ \+ \w+)',r' {0}'.format(result),line)
                print(line,end="")
        else:
            print(line,end="")
    file.close()


if __name__ == '__main__':
    process_crash('/tmp/crashes/d28744372ac8bb0d2ef26a8c994ce6f5dca06c1a/2016-08-26_13:53:06:1472190786/CoreDumpDemo-2016-08-26-135242.ips')