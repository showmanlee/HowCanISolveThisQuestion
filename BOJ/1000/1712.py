# 손익분기점
# https://www.acmicpc.net/problem/1712

a, b, c = list(map(int, input().split()))
res = 0
if b >= c:
    res = -1
else:
    res = a // (c - b) + 1
print(res)

# 대당 c원을 버는 공장의 고정 지출 비용이 a, 대당 생산 비용이 b일 때 손익분기점은?
# b가 c보다 크거나 같은 경우 손익분기점이 존재하지 않음(-1)
# while문을 돌릴 필요 없이, 공식 하나만 넣어주면 됨
