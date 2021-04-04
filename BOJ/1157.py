# 단어 공부
# https://www.acmicpc.net/problem/1157

count = [0 for i in range(26)]
s = input()
for c in s:
    if ord(c) >= ord('A') and ord(c) <= ord('Z'):
        count[ord(c) - ord('A')] += 1
    else:
        count[ord(c) - ord('a')] += 1
m = 0
e = 0
for c in count:
    if c > m:
        m = c
        e = 0
    if m == c:
        e += 1
if e > 1:
    print("?")
else:
    print(chr(ord('A') + count.index(m)))
