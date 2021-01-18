# 꼬리를 무는 숫자 나열
# https://www.acmicpc.net/problem/1598

a, b = list(map(int, input().split()))
ax = (a - 1) // 4
bx = (b - 1) // 4
ay = (a - 1) % 4
by = (b - 1) % 4
print(abs(ax - bx) + abs(ay - by))

# 4개씩 한 줄로자연수가 나열되어 있을 때 두 숫자의 맨하탄 거리는?
# x = (n - 1) // 4, y = (n - 1) % 4
