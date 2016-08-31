#!/usr/bin/env python3

from distutils.core import setup

setup(name='crashreportcli',
      version='1.0',
      description='iOS Crash Report Util Clis',
      author='wang yang',
      author_email='tomcat1991@126.com',
      packages=['crashreport','crashreport'],
      package_dir={'crashreport': 'src/crashreport'},
      package_data={'crashreport': ['src/crashreport/*.js']},
      scripts=['src/crashreport/htcrashreport']
     )