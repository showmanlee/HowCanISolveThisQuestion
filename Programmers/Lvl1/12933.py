# 정수 내림차순으로 배치하기
# https://programmers.co.kr/learn/courses/30/lessons/12933

def solution(n):
    answer = 0
    p = list(str(n))
    p.sort(reverse=True)
    pp = ''.join(p)
    answer = int(pp)
    return answer