# 별자리가 될 수 있다면
# https://www.acmicpc.net/problem/30821

n = int(input())
fact = [1, 1]
for i in range(2, n + 1):
    fact.append(fact[i - 1] * i)
print(fact[n] // (fact[n - 5] * fact[5]))

# 정n각형에서 5개의 꼭짓점을 이어 별을 만들 수 있는 경우의 수 출력하기

# nC5