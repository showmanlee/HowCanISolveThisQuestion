# 완전제곱수
# https://www.acmicpc.net/problem/1977

a = int(input())
b = int(input())
sq = []

for i in range(1, 101):
    if i * i > b:
        break
    if i * i >= a:
        sq.append(i * i)

if len(sq) == 0:
    print(-1)
else:
    print(sum(sq))
    print(sq[0])