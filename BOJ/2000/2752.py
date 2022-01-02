# 세수정렬
# https://www.acmicpc.net/problem/2752

l = list(map(int, input().split()))
l.sort()
for i in l:
    print(i, end=" ")