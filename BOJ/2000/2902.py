# KMP는 왜 KMP일까?
# https://www.acmicpc.net/problem/2902

p = input().split('-')
s = ''
for i in p:
    s += i[0]
print(s)

# 문자열을 임의의 문자로 split해서 그 첫글자(대문자 보장) 구하
