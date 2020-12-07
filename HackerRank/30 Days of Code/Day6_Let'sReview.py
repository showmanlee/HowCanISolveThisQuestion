# Day 6: Let's Review
# https://www.hackerrank.com/challenges/30-review-loop/problem

n = int(input())
for i in range(n):
    s = input()
    for j in range(0, len(s), 2):
        print(s[j], end='')
    print(' ', end='')
    for j in range(1, len(s), 2):
        print(s[j], end='')
    print()

# 1주차(입출력, 조건문, 반복문) 복습
# 문자열을 입력받고 짝수 번째 글자와 홀수 번째 글짜 따로 출력하기