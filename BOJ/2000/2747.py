# 피보나치 수
# https://www.acmicpc.net/problem/2747

n = int(input())
pib = [0, 1]
for i in range(2, n + 1):
    pib.append(pib[i - 2] + pib[i - 1])
print(pib[n])

# 피보나치 수 문제는 재귀보다는 DP로 푸는 것이 맞다