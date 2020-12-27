# Day 26: Nested Logic
# https:#www.hackerrank.com/challenges/30-nested-logic/problem

a, b, c = list(map(int, input().split()))
x, y, z = list(map(int, input().split()))
res = 0
if c > z:
    res = 10000
elif b > y and c == z:
    res = 500 * (b - y)
elif a > x and b == y and c == z:
    res = 15 * (a - x)
print(res)

# 주어진 문제 구현하기
# 복합 조건문 문제