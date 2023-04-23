# 부호
# https://www.acmicpc.net/problem/1247

for t in range(3):
    n = int(input())
    s = 0
    for i in range(n):
        p = int(input())
        s += p
    if s == 0:
        print(0)
    elif s > 0:
        print('+')
    else:
        print('-')

# 주어진 정수들의 합의 부호 출력하기

# 개별 정수들이 long long 범위를 꽉 맞춰서 나오기 때문에 python으로 하는 게 편하긴 함
# 다만 input 함수가 느리므로 python 3로는 시간 초과고, pypy를 써야 통과 가능