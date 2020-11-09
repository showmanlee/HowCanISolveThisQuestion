# 네 번째 점
# https://www.acmicpc.net/problem/3009

x = [0, 0, 0]
y = [0, 0, 0]
for i in range(3):
    x[i], y[i] = list(map(int, input().split()))
x4, y4 = [0, 0]
x.sort()
y.sort()
if x[0] == x[1]:
    x4 = x[2]
else:
    x4 = x[0]
if y[0] == y[1]:
    y4 = y[2]
else:
    y4 = y[0]
print(x4, y4)

# 플머 공식 데모 테스트 문제