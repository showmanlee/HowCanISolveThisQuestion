# 줄 서는 방법
# https://programmers.co.kr/learn/courses/30/lessons/12936

def solution(n, k):
    answer = []
    unused = []
    for i in range(0, n):
        unused.append(i + 1)
    k -= 1
    
    for i in range(n, 0, -1):
        print(unused)
        w = 1
        for j in range(1, i):
            w *= j
        p = k // w
        answer.append(unused[p])
        del unused[p]        
        k %= w
    return answer

# 모든 번호는 n번까지 순차적으로 주어짐