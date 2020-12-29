# Day 28: RegEx, Patterns, and Intro to Databases
# https://www.hackerrank.com/challenges/30-regex-patterns/problem

import math
import os
import random
import re
import sys

if __name__ == '__main__':
    N = int(input())
    res = []
    
    for N_itr in range(N):
        firstNameEmailID = input().split()
        firstName = firstNameEmailID[0]
        emailID = firstNameEmailID[1]
        if emailID.split('@')[1] == 'gmail.com':
            res.append(firstName)

    res.sort()
    for s in res:
        print(s)

# 정규 표현식 또는 split을 통한 데이터 추출
# gmail.com 이메일을 가지고 있는 사람의 이름을 오름차순으로 표시