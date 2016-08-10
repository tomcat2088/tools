logFields = ["req_time","url"]
logFieldsColor = ["yellow","cyan"]
logFieldsShowType = ["all","all"]

#['id','method','url','req_time','req_headers','req_data','resp_time','resp_headers','resp_data']
def logStr(fieldName,value):
    funcMap = {"req_time":timeLogStr,
    "req_headers":dictLogStr,
    "req_data":binaryLogStr,
    "resp_time":timeLogStr,
    "resp_headers":dictLogStr,
    "resp_data":binaryLogStr}
    logStrFunc = funcMap[fieldName]
    if logStrFunc:
        logStrFunc(value,)


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
