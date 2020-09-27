# 기지국 설치
# https://programmers.co.kr/learn/courses/30/lessons/12979

import math

def solution(n, stations, w):
    answer = 0
    width = w * 2 + 1
    coverage = []
    for s in stations:
        coverage.append(s - w)
        coverage.append(s + w)
    if coverage[0] > 0:
        answer = math.ceil((coverage[0] - 1) / width)
    for i in range(1, len(coverage) - 1, 2):
        gap = coverage[i + 1] - coverage[i] - 1
        if gap >= 1:
            answer += math.ceil(gap / width)
    if coverage[-1] <= n:
        answer += math.ceil((n - coverage[-1]) / width)
        
    return answer