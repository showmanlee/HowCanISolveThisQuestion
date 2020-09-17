# 문자열 압축(2020 카카오)
# https://programmers.co.kr/learn/courses/30/lessons/60057

def solution(s):
    answer = 0
    answers = []
    for i in range(1, len(s) + 1):
        stubs = []
        counts = []
        index = -1;
        for m in range(0, len(s), i):
            ss = ""
            if m+i > len(s):
                ss = s[m:len(s)]
            else:
                ss = s[m:m+i]
            
            if (index == -1 or stubs[index] != ss):
                stubs.append(ss)
                counts.append(1)
                index += 1
            elif (stubs[index] == ss):
                counts[index] += 1
                        
        result = ""
        for j in range(0, len(stubs)):
            result += stubs[j]
            if counts[j] > 1:
                result += str(counts[j])
        answers.append(len(result))
        
    answer = min(answers)            
    return answer

# 문자열은 정해진 길이만큼 자르고, 남은 부분은 그대로 쓴다.