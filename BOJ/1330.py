# 두 수 비교하기
# https://www.acmicpc.net/problem/1330

a, b = input().split()
if int(a) > int(b):
    print(">")
elif int(a) < int(b):
    print("<")
else:
    print("==")