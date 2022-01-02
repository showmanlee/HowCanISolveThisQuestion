# 수도요금
# https://www.acmicpc.net/problem/10707

x = int(input())
yd = int(input())
yl = int(input())
ya = int(input())
p = int(input())
resx = x * p
resy = yd
if p > yl:
    resy += ya * (p - yl)
if resx > resy:
    print(resy)
else:
    print(resx)

# 기본요금이 있는 요금제와 없는 요금제 중 가장 싼 가격은?