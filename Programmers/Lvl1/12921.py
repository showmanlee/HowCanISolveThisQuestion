# 소수 찾기
# https://programmers.co.kr/learn/courses/30/lessons/12921

import math

def isPrime(n):
    if n <= 1:
        return 0
    for i in range(2, int(math.sqrt(n)) + 1):
        if n % i == 0:
            return 0
    return 1

def solution(n):
    answer = 0
    for i in range(0, n + 1):
        answer += isPrime(i)
    return answer