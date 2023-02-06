import json
import requests
import datetime

#server ip addr: 8.129.5.136

studentID = "12132276"
url = "http://reservation.ruichengyunqin.com/api/blade-app/qywx/saveOrder?userid=" + studentID

customerID = "1427570050142879746"
customerName = "梁志辉"
customerTel = "18274705630"

presonalInfo = {"customerId": customerID, 
                "customerName": customerName, 
                "customerTel": customerTel, 
                "userNum": 2, 
                "customerEmail":""}

gymID = {"teacher tennis": "1297443539294167042", "runyang": "1297443858304540673"}
runyangGroundID = {'1':'', '2':'', '3':'1298272615009411073'} 

gymInfo = {"gymId": gymID["runyang"],
           "gymName": "润杨羽毛球馆",
           "groundId": runyangGroundID["3"],
           "groundName": "3号场",
           "groundType": "0",
           "messagePushType": "0",
           "isIllegal": "0"}


nowTime = datetime.datetime.now()
nowTimeStr = nowTime.strftime('%Y-%m-%d %H:%M:%S')
rvTime = datetime.datetime.now() + datetime.timedelta(days=7)  # Reserve time, Refresh at days=6
rvTimeStrStart = rvTime.strftime('%Y-%m-%d') + " 09:00:00"
rvTimeStrEnd = rvTime.strftime('%Y-%m-%d') + " 11:30:00"

timeInfo = {"orderDate": nowTimeStr,
            "startTime": rvTimeStrStart,
            "endTime": rvTimeStrEnd,
            "tmpOrderDate": nowTimeStr,
            "tmpStartTime": rvTimeStrStart,
            "tmpEndTime": rvTimeStrEnd,}

headers = {
    "Content-Type": 'application/json',
    "User-Agent": "Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/81.0.4044.138 Safari/537.36 NetType/WIFI MicroMessenger/7.0.20.1781(0x6700143B) WindowsWechat(0x63060012)"
}

def autoReserve(personalInfo, gymInfo, timeInfo):
    data = dict(personalInfo, **gymInfo, **timeInfo)
    response = requests.post(url=url, headers=headers, data=json.dumps(data))
    print(response.text)
    
    if '成功' in response.text:
        print("场地预约成功")
    else:
        print("场地预约失败")


# autoReserve(presonalInfo, gymInfo, timeInfo)
while True:
    nowTime = datetime.datetime.now()
    nowTimeStr = nowTime.strftime('%Y-%m-%d %H:%M:%S')
    timeInfo["orderDate"] = nowTimeStr
    timeInfo["tmpOrderDate"] = nowTimeStr
    cur = nowTime.strftime('%H:%M:%S')
    if cur != '20:00:00':
        print(f"没有到 20:00:00, 现在是 {cur}")
        continue
    else:
        autoReserve(presonalInfo, gymInfo, timeInfo)
        break
