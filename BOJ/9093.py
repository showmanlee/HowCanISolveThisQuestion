# 단어 뒤집기
# https://www.acmicpc.net/problem/9093

n = int(input())
for i in range(n):
    words = input().split()
    for c in words:
        for j in range(1, len(c) + 1):
            print(c[-j], end='')
        print(' ', end='')
    print()

# 문장의 단어를 모두 뒤집어서 출력하기
# 일반적인 역출력 문제?
