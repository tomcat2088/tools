#!/usr/local/bin/python3

from http.client import HTTPConnection
from urllib.parse import *
import sys
from xml.dom import minidom

def parse_translated_xml(xml):
	doc = minidom.parseString(xml)
	translations = doc.getElementsByTagName('translation')
	for key in translations:
		print(key.firstChild.firstChild.wholeText)


if len(sys.argv) <= 1:
	print("Usage:")
	exit()
word = quote(sys.argv[1]);
conn = HTTPConnection('dict.youdao.com');
conn.request('GET','/fsearch?q='+word+'&keyfrom=mac.main&id=4E57E4CB9C43F4DEF4375A20D7F21409&vendor=fanyiindex&appVer=2.0.2&client=macdict&le=eng')
response = conn.getresponse();
xml = response.read();
parse_translated_xml(xml)