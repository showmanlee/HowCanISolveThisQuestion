# Day 20: Sorting
# https://www.hackerrank.com/challenges/30-sorting/problem

import sys

n = int(input().strip())
a = list(map(int, input().strip().split(' ')))

swaped = 0
for i in range(n):
    for j in range(n - 1):
        if a[j] > a[j+1]:
            a[j], a[j+1] = a[j+1], a[j]
            swaped += 1

print("Array is sorted in", swaped, "swaps.")
print("First Element:", a[0])
print("Last Element:", a[n-1])


# 버블 정렬 구현하고 교체 횟수 구하기
