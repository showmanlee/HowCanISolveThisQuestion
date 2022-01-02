# 시험 감독
# https://www.acmicpc.net/problem/13458

import math
n = int(input())
a = list(map(int, input().split()))
b, c = list(map(int, input().split()))
answer = 0
for i in a:
    if i <= b:
        answer += 1
    else:
        answer += math.ceil((i - b) / c) + 1
print(answer)

# math.ceil, math.floor, round
