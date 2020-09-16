# 수박수박수박수박수박수?
# https://programmers.co.kr/learn/courses/30/lessons/12922

def solution(n):
    answer = ''
    for i in range(n):
        answer += '수' if i % 2 == 0 else '박'
    return answer