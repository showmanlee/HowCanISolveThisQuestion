# Day 2: Operators
# https://www.hackerrank.com/challenges/30-operators/problem

import math
import os
import random
import re
import sys

def solve(meal_cost, tip_percent, tax_percent):
    res = meal_cost + (tip_percent / 100 * meal_cost) + (tax_percent / 100 * meal_cost)
    print(round(res))

if __name__ == '__main__':
    meal_cost = float(input())

    tip_percent = int(input())

    tax_percent = int(input())

    solve(meal_cost, tip_percent, tax_percent)

# 고기 가격, 팁, 세금 비율이 주어졌을 때 최종 구매가를 반올림하여 출력하기
# 이 언어에서 round 함수를 쓰는 법을 아나요? - 내장된 round 사용