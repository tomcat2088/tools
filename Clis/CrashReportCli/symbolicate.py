import io
import re
import debug_symbol_manager

def process_crash(crash_file):
    file = open(crash_file)
    while True:
        line = file.readline()
        if len(line) == 0:
            break
        ret = re.match(r'^\d+\s+(\w+)\s+(\w+)\s+(\w+)',line)
        if ret:
            app_name = ret.group(1)
            address = ret.group(2)
            base_address = ret.group(3)
    file.close()


if __name__ == '__main__':
    process_crash('/tmp/crashes/d28744372ac8bb0d2ef26a8c994ce6f5dca06c1a/2016-08-26_17:48:17:1472204897/CoreDumpDemo-2016-08-26-174705.ips')