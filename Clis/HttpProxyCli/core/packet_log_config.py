from termcolor import colored
import sys
sys.path.append('..')
from config.log import *

_filter = ""
def setFilter(filter):
    global _filter
    _filter = filter

def canBeShow(value):
    global _filter
    if _filter == "":
        return True
    if str(value).rfind(_filter) < 0:
        return False
    return True

def logStr(fieldName,value):
    funcMap = {"requestTime":timeLogStr,
    "requestHeaders":dictLogStr,
    "requestData":binaryLogStr,
    "responseTime":timeLogStr,
    "responseHeaders":dictLogStr,
    "responseData":binaryLogStr}
    output = ''
    if fieldName in funcMap:
        logStrFunc = funcMap[fieldName]
        if logStrFunc:
            index = logFields.index(fieldName)
            output = logStrFunc(value,logFieldsShowType[index])
    else:
        output = defaultLog(value,'')

    index = logFields.index(fieldName)
    output = colored(output,logFieldsColor[index])
    return output

def defaultLog(value,showType):
    return str(value)

def timeLogStr(time,showType):
    return time.strftime('%m-%d %H:%M:%S')

def dictLogStr(value,showType):
    if showType == "all":
        return str(value)
    elif showType == "summary":
        return str.format('{0} keys & vals',len(value))
    return ""

def binaryLogStr(value,showType):
    if showType == "all":
        return str(value,"utf-8")
    elif showType == "summary":
        return str.format('{0} bytes',len(value))
    return ""
