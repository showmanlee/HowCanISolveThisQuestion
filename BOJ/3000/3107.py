# IPv6
# https://www.acmicpc.net/problem/3107

v6 = input().split(':')
for i in range(len(v6)):
    if len(v6[i]) < 4 and v6[i] != '':
        for j in range(4 - len(v6[i])):
            v6[i] = '0' + v6[i]
if len(v6) > 8:
    v6.remove('')
if len(v6) < 8:
    p = v6.index('')
    v6[p] = '0000'
    while len(v6) < 8:
        v6.insert(p, '0000')
if '' in v6:
    v6[v6.index('')] = '0000'
res = ''
for s in v6:
    res += s
    res += ':'
if res[-1] == ':':
    res = res[:-1]
print(res)

# 축약된 IPv6 주소를 원래 형태로 바꾸기
# 앞자리의 0 생략 가능, 연속된 0000을 ::로 생략 가능
# 한 개의 0000도 ::로 수정할 수 있음에 주의 
