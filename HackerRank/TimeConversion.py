# Time Conversion
# https://www.hackerrank.com/challenges/time-conversion/problem

def timeConversion(s):
    h = int(s[0:2])
    m = int(s[3:5])
    e = int(s[6:8])
    if s[8:] == 'PM':
        h += 12
        if h == 24:
            h = 12
    elif h == 12:
        h = 0
    return str(h).zfill(2) + ':' + str(m).zfill(2) + ':' + str(e).zfill(2)

# 12시간 시간을 받아서 24시간 시간으로 변환
# 12:00:00AM은 00:00:00, 12:00:00PM은 12:00:00으로 변환되어야 함에 주의
# str.zfill()로 앞자리에 0 채우기
