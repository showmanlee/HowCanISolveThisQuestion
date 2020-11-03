# 2007년
# https://www.acmicpc.net/problem/1924

import datetime

m, d = list(map(int, input().split()))
dt = datetime.date(2007, m, d).weekday()
if dt == 0:
    print("MON")
elif dt == 1:
    print("TUE")
elif dt == 2:
    print("WED")
elif dt == 3:
    print("THU")
elif dt == 4:
    print("FRI")
elif dt == 5:
    print("SAT")
elif dt == 6:
    print("SUN")

# datetime.date.weekday()
# 여긴 월요일이 0
