# Day 5: Loops
# https://www.hackerrank.com/challenges/30-loops/problem

#!/bin/python3

import math
import os
import random
import re
import sys

if __name__ == '__main__':
    n = int(input())
    for i in range(1, 11):
        print(str(n) + " x " + str(i) + " = " + str(n * i))

# 반복문으로 구구단 출력