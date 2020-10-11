# 평균
# https://www.acmicpc.net/problem/1546

n = int(input())
a = list(map(int, input().split()))
m = max(a)
for i in range(n):
    a[i] = a[i] / m * 100
print(sum(a) / n)
