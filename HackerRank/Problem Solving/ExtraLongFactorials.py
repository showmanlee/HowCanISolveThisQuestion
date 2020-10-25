# Extra Long Factorials
# https://www.hackerrank.com/challenges/extra-long-factorials/problem

def extraLongFactorials(n):
    p = 1
    for i in range(1, n + 1):
        p *= i
    print(p)

# 큰 수의 팩토리얼(~100)