# 프렌즈4블록(2018 카카오)
# https://programmers.co.kr/learn/courses/30/lessons/17679

def solution(m, n, board):
    answer = 0
    shape = []
    checker = []
    for s in board:
        shape.append(list(s))
        checker.append(['N'] * len(s))
        
    while True:
        check = False
        for i in range(0, m - 1):
            for j in range(0, n - 1):
                if shape[i][j] == shape[i][j+1] and shape[i][j] == shape[i+1][j+1] and shape[i][j] == shape[i+1][j] and checker[i][j] != ' ':
                    check = True 
                    checker[i][j] = checker[i][j+1] = checker[i+1][j] = checker[i+1][j+1] = 'P'
        if check == False:
            break
            
        for i in range(0, m):
            for j in range(0, n):
                if checker[i][j] == 'P':
                    answer += 1
                    shape[i][j] = checker[i][j] = ' '
        
        for i in range(m - 2, -1, -1):
            for j in range(0, n):
                if shape[i][j] != ' ' and shape[i+1][j] == ' ':
                    for k in range(i, m - 1):
                        if shape[k+1][j] != ' ':
                            break
                        p = shape[k][j]
                        shape[k][j] = shape[k+1][j]
                        shape[k+1][j] = p
        
        for i in range(0, m):
            for j in range(0, n):
                if shape[i][j] == ' ':
                    checker[i][j] = ' '
                else:
                    checker[i][j] = 'N'
    return answer