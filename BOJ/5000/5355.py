# 화성 수학
# https://www.acmicpc.net/problem/5355

t = int(input())
for tt in range(t):
    s = input().split()
    n = float(s[0])
    for i in range(1, len(s)):
        if (s[i] == '@'):
            n *= 3
        if (s[i] == '%'):
            n += 5
        if (s[i] == '#'):
            n -= 7
    print('%.2f' % n)

# @는 3을 곱하고, %는 5를 더하며, #는 7을 빼는 연산자일 때, 실수 n에 다음의 연산자를 적용한 결과는?
# python에서의 자릿수 출력법은 저렇게
