# Day 9: Recursion 3
# https://www.hackerrank.com/challenges/30-recursion/problem

import math
import os
import random
import re
import sys

def factorial(n):
    if n <= 1:
        return n
    return n * factorial(n - 1)

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    result = factorial(n)

    fptr.write(str(result) + '\n')

    fptr.close()

# 재귀 함수로 팩토리얼 짜기
# factorial(n) = n * factorial(n - 1)
# (factorial(1) = 1)