# 전화번호 목록
# https://programmers.co.kr/learn/courses/30/lessons/42577

def solution(phone_book):
    for i in phone_book:
        for j in phone_book:
            if i != j:
                if j[:len(i)] == i:
                    return False
    return True