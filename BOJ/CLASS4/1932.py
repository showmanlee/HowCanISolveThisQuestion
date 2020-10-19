# 정수 삼각형
# https://www.acmicpc.net/problem/1932

n = int(input())
a = []
for i in range(n):
    aa = list(map(int, input().split()))
    a.append(aa)
    
dp = [[0 for i in range(n)] for i in range(n)]
for i in range(n - 1, -1, -1):
    for j in range(i, -1, -1):
        if i == n - 1:
            dp[i][j] = a[i][j]
        else:
            dp[i][j] = a[i][j] + max([dp[i+1][j], dp[i+1][j+1]])
print(dp[0][0])

# 이거 프로그래머스에서 풀어봤어
# 이번엔 Python으로
