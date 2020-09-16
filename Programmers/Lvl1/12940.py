# 최대공약수와 최소공배수
# https://programmers.co.kr/learn/courses/30/lessons/12940

def gcd(n, m):
    g = 1
    for i in range(1, n + 1):
        if n % i == 0 and m % i == 0:
            g = i
    return g
    
def lcm(n, m):
    i = 1
    while True:
        if n * i % m == 0:
            break
        i += 1
    return n * i

def solution(n, m):
    answer = []
    if n > m:
        n, m = m, n
    answer += [gcd(n, m), lcm(n, m)]
    return answer