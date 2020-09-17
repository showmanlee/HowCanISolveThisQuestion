# 멀쩡한 사각형
# https://programmers.co.kr/learn/courses/30/lessons/62048

import math

def solution(w,h):
    answer = w * h - (w + h - math.gcd(w, h)) 
    return answer

# 공식 = 가로 * 세로 - (가로 + 세로 - 최대공약수)
# Python엔 최대공약수/최소공배수 함수가 있음