# 조합
# https://www.acmicpc.net/problem/2407

n, m = list(map(int, input().split()))
fact = [0, 1]
for i in range(2, n + 1):
    fact.append(fact[i - 1] * i)
print(fact[n] // (fact[n - m] * fact[m]))

# 순열 = nPr = n! / (n-r)!
# 조합 = nCr = n! / ((n-r)! * r!) = nPr / r!
# 순서를 생각하며 or 무시하고 n개 중 r개 뽑기