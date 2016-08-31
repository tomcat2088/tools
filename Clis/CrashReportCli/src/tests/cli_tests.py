#!/usr/bin/env python3

import sys
import crashreport.cli
import unittest

class TestCli(unittest.TestCase):
    def test_symbol_collect(self):
      src = '/Users/ocean/Library/Developer/Xcode/DerivedData/epmyg-gtybwblmvlvtczarceddhsukxhhg/Build/Products/Debug-iphonesimulator/'
      app_name = 'epmyg'
      crashreport.cli.main(['cdsym',src,app_name])
    def test_symbolicate(self):
        crashreport.cli.main(['-v', 'fsymbolicate', '/Users/ocean/Documents/crashes/epmyg.crash'])

if __name__ == '__main__':
    unittest.main()