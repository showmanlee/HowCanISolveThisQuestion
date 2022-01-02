# 지능형 기차
# https://www.acmicpc.net/problem/2455

cur = 0
res = 0
for i in range(4):
    p = list(map(int, input().split()))
    cur += p[1] - p[0]
    res = max(res, cur)
print(res)

# 4개의 역에 내리고 타는 사람이 주어졌을 때, 기차에 사람이 가장 많을 때의 사람 수는?
# 빼고 더하고 갱신하고