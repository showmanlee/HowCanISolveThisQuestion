# 소수
# https://www.acmicpc.net/problem/2581

import math

minn = int(input())
maxx = int(input())
res = []

def isPrime(n):
    if n == 1:
        return False
    for i in range(2, int(math.sqrt(n)) + 1):
        if n % i == 0:
            return False
    return True

for i in range(minn, maxx + 1):
    if isPrime(i):
        res.append(i)

if len(res) == 0:
    print(-1)
else:
    print(sum(res))
    print(res[0])
