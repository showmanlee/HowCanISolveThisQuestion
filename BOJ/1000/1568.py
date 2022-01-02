# 새
# https://www.acmicpc.net/problem/1568

n = int(input())
t = 1
res = 0
while n > 0:
    if t > n:
        t = 1
        continue
    n -= t
    t += 1
    res += 1
print(res)

# n마리의 새를 1마리부터 차례대로 날려보내는데, 현재 부르는 수가 남아있는 새보다 클 경우 1부터 다시 센다
# 이때 새를 다 날리는데 걸리는 시간은?
# 계속 반복으로 풀면 되려나
