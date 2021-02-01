# 진짜 공간
# https://www.acmicpc.net/problem/1350

import math

n = int(input())
files = list(map(int, input().split()))
clust = int(input())
res = 0
for i in files:
    res += math.ceil(i / clust)
print(res * clust)

# 파일의 실제 크기가 주어질 때, 클러스터 크기에 따른 실제 점유 용량 구하기
# ceil * clust