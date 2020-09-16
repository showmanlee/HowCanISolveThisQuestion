# 2016년
# https://programmers.co.kr/learn/courses/30/lessons/12901

def solution(a, b):
    dayHave = [31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
    day = 0
    for i in range(0, a - 1):
        day += dayHave[i]
    day += b
    answer = ''
    
    if day % 7 == 0:
        answer = 'THU'
    elif day % 7 == 1:
        answer = 'FRI'
    elif day % 7 == 2:
        answer = 'SAT'
    elif day % 7 == 3:
        answer = 'SUN'
    elif day % 7 == 4:
        answer = 'MON'
    elif day % 7 == 5:
        answer = 'TUE'
    elif day % 7 == 6:
        answer = 'WED'
    return answer