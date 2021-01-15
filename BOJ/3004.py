# 체스판 조각
# https://www.acmicpc.net/problem/3004

n = int(input())
res = 2
ctr = 2
for i in range(2, n + 1):
    res += ctr
    if i % 2 == 1:
        ctr += 1
print(res)

# 체스판을 직각으로 n번 잘랐을 때 나올 수 있는 최대 조각 수는?
# 가로 세로 가로 세로 자르면 많이 나온다
# 2 4 6 9 12 16 20 25 30 36...
# 2부터 시작해 2번 자를 때마다 추가 조각 수를 +1
