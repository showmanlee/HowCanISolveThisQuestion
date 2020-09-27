// n진수 게임(2018 카카오)
// https://programmers.co.kr/learn/courses/30/lessons/17687

def solution(n, t, m, p):
    answer = ''
    chars = "0123456789ABCDEF"
    index = -1
    count = -1
    while len(answer) < t:
        count += 1
        a = count
        num = ""
        if a == 0:
            num = '0'
        while a > 0:
            num = chars[a % n] + num
            a //= n
        for c in num:
            index += 1
            if index % m == p - 1:
                answer += c
    return answer[:t]