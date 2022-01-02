# 피보나치 수 2
# https://www.acmicpc.net/problem/2748

n = int(input())
pib = [0, 1]
for i in range(2, n + 1):
    pib.append(pib[i - 2] + pib[i - 1])
print(pib[n])

# 입력 최대치가 2배 - 재귀로는 부담스러워지기 시작