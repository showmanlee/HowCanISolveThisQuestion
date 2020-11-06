# 주사위 세개
# https://www.acmicpc.net/problem/2480

a, b, c = list(map(int, input().split()))
res = 0
if a == b and b == c:
    res = 10000 + a * 1000
elif a == b or a == c:
    res = 1000 + a * 100
elif b == c:
    res = 1000 + b * 100
else:
    res = max([a, b, c]) * 100
print(res)

# 3개 맞니, 2개 맞니, 1개 맞니?
    