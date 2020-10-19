# A+B - 7
# https://www.acmicpc.net/problem/11021

n = int(input())
for i in range(1, n + 1):
    a, b = list(map(int, input().split()))
    print("Case #" + str(i) + ": " + str(a+b))

# Case 번호 붙이기
