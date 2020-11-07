# 더하기 사이클
# https://www.acmicpc.net/problem/1110

n = int(input())
p = n
res = 0
while(True):
    a = p // 10
    b = p % 10
    c = a + b
    p = int(str(b) + str(c % 10))
    res += 1
    if (n == p):
        break
print(res)

# python에서 do-while문 구현하
