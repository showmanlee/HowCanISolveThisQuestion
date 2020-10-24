# 피보나치 수 4
# https://www.acmicpc.net/problem/10826

pib = [0, 1]
n = int(input())
for i in range(2, n + 1):
    pib.append(pib[i - 1] + pib[i - 2])
print(pib[n])

# 10000번째 피보나치 수를 구하라
# 참고로 10000번째 피보나치 수는 2090자리 수 -> C++에서는 문자열 기반 연산 필수
