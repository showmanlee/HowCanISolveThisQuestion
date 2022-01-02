# 다면체
# https://www.acmicpc.net/problem/10569

n = int(input())
for i in range(n):
    v, e = list(map(int, input().split()))
    print(2 - v + e)

# 꼭짓점의 수와 모서리의 수가 주어질 때, 볼록다면체를 만들 수 있는 면의 수 구하기
# v - e + f = 2래요