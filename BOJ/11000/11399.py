# ATM
# https://www.acmicpc.net/problem/11399

ans = 0
n = int(input())
p = list(map(int, input().split()))
p.sort()
for i in range(1, n + 1):
    ans += sum(p[:i])
print(ans)