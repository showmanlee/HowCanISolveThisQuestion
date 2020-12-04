# Day 3: Intro to Conditional Statements
# https://www.hackerrank.com/challenges/30-conditional-statements/problem

if __name__ == '__main__':
    N = int(input())
    if N % 2 == 1:
        print("Weird")
    elif N >= 2 and N <= 5:
        print("Not Weird")
    elif N >= 6 and N <= 20:
        print("Weird")
    else:
        print("Not Weird")


# 조건문 만들기
# 이건 좀 다르지