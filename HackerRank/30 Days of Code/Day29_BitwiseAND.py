# Day 29: Bitwise AND
# https:#www.hackerrank.com/challenges/30-bitwise-and/problem

#!/bin/python3

import math
import os
import random
import re
import sys

if __name__ == '__main__':
    t = int(input())

    for t_itr in range(t):
        nk = input().split()

        n = int(nk[0])
        k = int(nk[1])
        
        res = 0
        for i in range(1, n):
            for j in range(i + 1, n + 1):
                if (i & j) > res and (i & j) < k:
                    res = i & j
        print(res)

# 1~n까지 수 사이에 AND 연산한 결과 중 k 미만의 가장 큰 값 출력하기
# 30 Days of Code 끝! 올 한 해 마무리 잘 하시길 바랍니다
# 이제 문풀에 집중합시다