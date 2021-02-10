# 숫자 놀이
# https://www.acmicpc.net/problem/2145

while True:
    n = int(input())
    if n == 0:
        break
    p = n;
    while p // 10 != 0:
        q = 0
        for c in str(p):
            q += int(c)
        p = q
    print(p)

# 수의 각 자릿수를 계속 더해서 한자릿수로 만들 때 그 값은?
