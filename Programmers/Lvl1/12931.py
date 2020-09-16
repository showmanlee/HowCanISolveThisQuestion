# 자릿수 만들기
# https://programmers.co.kr/learn/courses/30/lessons/12931

def solution(n):
    answer = 0
    nn = str(n)
    for c in nn:
        answer += int(c)

    return answer