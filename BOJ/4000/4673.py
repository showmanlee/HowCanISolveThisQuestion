# 셀프 넘버
# https://www.acmicpc.net/problem/4673

l = []
for i in range(10000, 0, -1):
    l.append(i)
    s = str(i)
    sn = i
    for c in s:
        sn += int(c)
    if sn in l:
        l.remove(sn)
l.sort()
for n in l:
    print(n)
