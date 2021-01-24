# 거스름돈
# https://www.acmicpc.net/problem/5585

n = 1000 - int(input())
res = 0
res += n // 500
n -= n // 500 * 500
res += n // 100
n -= n // 100 * 100
res += n // 50
n -= n // 50 * 50
res += n // 10
n -= n // 10 * 10
res += n // 5
n -= n // 5 * 5
res += n
print(res)

# 1000엔짜리 지폐를 냈을 때, 500, 100, 50, 10, 5, 1엔 동전으로 거슬러줄 수 있는 동전의 최소 수
