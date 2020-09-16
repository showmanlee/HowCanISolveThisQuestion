# 네트워크
# https://programmers.co.kr/learn/courses/30/lessons/43162

check = []

def dfs(n, computers, index):
    global check
    check[index] = True
    for i in range(0, n):
        if not check[i] and computers[index][i] == 1:
            dfs(n, computers, i)

def solution(n, computers):
    global check
    answer = 0
    for i in range(0, n):
        check.append(False)
    
    for i in range(0, n):
        if not check[i]:
            dfs(n, computers, i)
            answer += 1
    return answer

# dfs 문제