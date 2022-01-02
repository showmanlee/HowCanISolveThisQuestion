# 파티가 끝나고
# https://www.acmicpc.net/problem/2845

l, p = list(map(int, input().split()))
a = list(map(int, input().split()))
for i in a:
    print(i - (l * p), end=' ')

# l * p와 a[5] 내 각 원소와의 
