# 자연수 뒤집어 배열로 만들기
# https://programmers.co.kr/learn/courses/30/lessons/12932

def solution(n):
    answer = []
    nn = str(n)
    for i in range(len(nn) - 1, -1, -1):
        answer.append(int(nn[i]))
    return answer