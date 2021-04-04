# X보다 작은 수
# https://www.acmicpc.net/problem/10871

_, n = input().split()
arr = input().split()
for a in arr:
    if int(n) > int(a):
        print(a + " ", end="")
