# 팩토리얼 3
# https://www.acmicpc.net/problem/27434

n = int(input())
res = 1
while (n >= 1) :
    res *= n
    n -= 1
print(res)