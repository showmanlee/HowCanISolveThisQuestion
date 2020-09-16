# 제일 작은 수 제거하기
# https://programmers.co.kr/learn/courses/30/lessons/12935

def solution(arr):
    m = min(arr)
    del arr[arr.index(m)]
    if len(arr) == 0:
        arr.append(-1)
    return arr