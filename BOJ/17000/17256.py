# 달달함이 넘쳐흘러
# https://www.acmicpc.net/problem/17256

ax, ay, az = list(map(int, input().split()))
cx, cy, cz = list(map(int, input().split()))
print(cx - az, cy // ay, cz - ax)

# a # b = (a.z + b.x, a.y * b.y, a.x + b.z)일 때, a # b = c를 만족하는 b 구하기
# 계산 과정 잘 보고 사칙연산 활용하기
