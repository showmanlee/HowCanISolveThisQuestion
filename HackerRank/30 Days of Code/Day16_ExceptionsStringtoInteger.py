# Day 16: Exceptions - String to Integer
# https://www.hackerrank.com/challenges/30-exceptions-string-to-integer/problem

import sys


S = input().strip()

try:
    print(int(S))
except:
    print("Bad String")

# 예외 처리로 숫자만 있는 문자열 구분하기
# try... except