# Day 25: Running Time and Complexity
# https://www.hackerrank.com/challenges/30-running-time-and-complexity/problem

import math

def isPrime(n):
    if n == 1:
        return False
    for i in range(2, int(math.sqrt(n)) + 1):
        if n % i == 0:
            return False
    return True
    
t = int(input())
for i in range(t):
    n = int(input())
    if isPrime(n):
        print("Prime")
    else:
        print("Not prime")

# 소수 알고리즘 짜는데, O(n^2)가 나오지 않게 하기
# sqrt(n)까지 계산해도 됨