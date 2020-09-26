# 다음 큰 숫자
# https://programmers.co.kr/learn/courses/30/lessons/12911

def solution(n):
    np = n
    goal = 0
    while np > 0:
        if np % 2 == 1:
            goal += 1
        np //= 2
    
    answer = n + 1
    while True:
        a = answer
        c = 0
        while a > 0:
            if a % 2 == 1:
                c += 1
            a //= 2
        if c == goal:
            return answer
        answer += 1
    return answer