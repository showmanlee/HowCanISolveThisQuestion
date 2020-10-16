# 이항 계수 1
# https://www.acmicpc.net/problem/11050

fact = [1]
for i in range(1, 11):
    fact.append(fact[i - 1] * i)

n, k = list(map(int, input().split()))
print(fact[n] // (fact[k] * fact[n - k]))
# n, k의 이항계수 -> n! / (k! * (n - k)!)
