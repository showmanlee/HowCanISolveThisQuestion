# 홀수
# https://www.acmicpc.net/problem/2576

odd = []
for i in range(7):
    n = int(input())
    if n % 2 == 1:
        odd.append(n)

if len(odd) == 0:
    print(-1)
else:
    odd.sort()
    print(sum(odd))
    print(odd[0])