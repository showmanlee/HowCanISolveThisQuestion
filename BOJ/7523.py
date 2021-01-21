# Gauß
# https://www.acmicpc.net/problem/7523

n = int(input())
for i in range(1, n + 1):
    a, b = list(map(int, input().split()))
    res = (b - a) * (b - a + 1) // 2
    res += a * (b - a + 1)
    print("Scenario #" + str(i) + ":")
    print(res)
    print()

# a부터 b까지의 합 구하기
# 직관적으로 만든 저 수식을 더 줄일 수 있을까 - (b + a) * (b - a + 1) // 2
