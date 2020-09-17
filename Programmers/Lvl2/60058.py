# 괄호 변환(2020 카카오)
# https://programmers.co.kr/learn/courses/30/lessons/60058

def ho(p):
    if p == "":				# 1
        return "" 			
    
    index = 0				# 2
    check = 0
    for i in range(0, len(p)):
        check += 1 if p[i] == '(' else -1
        if check == 0:
        	index = i + 1
        	break
    u = p[:index]
    v = p[index:]
    
    check = 0				# 3
    for i in range(0, len(u)):
        check += 1 if u[i] == '(' else -1
        if check < 0:
            break
    if check == 0:
        return u + ho(v)
    
    uu = ""						# 4
    for i in range(1, len(u) - 1):
        uu += "(" if u[i] == ")" else ")"
    return "(" + ho(v) + ")" + uu     

def solution(p):
    answer = ho(p)
    return answer