# 소수 찾기
# https://programmers.co.kr/learn/courses/30/lessons/42839

import math
import itertools

def isPrime(n):
    if n <= 1:
        return 0
    sqr = int(math.sqrt(n))
    for i in range(2, sqr + 1):
        if n % i == 0:
            return 0
    return 1

def solution(numbers):
    global result
    answer = 0
    num = list(numbers)
    ls = []
    result = set()
    for k in range(1, len(num) + 1):
        ls += itertools.permutations(num, k)
    for l in ls:
        s = ""
        result.add(int(s.join(l)))
    
    for r in result:
        answer += isPrime(r)
    
    return answer

# itertools.permutations