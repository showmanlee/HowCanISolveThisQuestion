# 콜라츠 추측
# https://programmers.co.kr/learn/courses/30/lessons/12943

def solution(num):
    answer = 0
    if num == 1:
        return 0
    for i in range(1, 501):
        if num % 2 == 0:
            num /= 2
        else:
            num = num * 3 + 1
        if num == 1:
            return i
    return -1