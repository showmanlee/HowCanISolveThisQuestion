# A+B - 6
# acmicpc.net/problem/10953

n = int(input())
for i in range(n):
    a, b = list(map(int, input().split(',')))
    print(a+b)

# ,로 스플릿