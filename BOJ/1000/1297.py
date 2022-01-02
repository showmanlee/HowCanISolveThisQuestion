# TV 크기
# https://www.acmicpc.net/problem/1297

import math

s, h, w = list(map(int, input().split()))
m = s / math.sqrt(h * h + w * w)
print(math.floor(h * m), math.floor(w * m))

# 피타고라스의 실수배