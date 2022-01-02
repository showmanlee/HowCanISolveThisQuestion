# A+B - 8
# https://www.acmicpc.net/problem/11022

n = int(input())
for i in range(1, n + 1):
    a, b = list(map(int, input().split()))
    print("Case #" + str(i) + ": " + str(a) + " + " + str(b) + " = " + str(a+b))

# 7번에서 a + b까지