# 2*n 타일링
# https://www.acmicpc.net/problem/11726

n = int(input())
answer = 1
p = [1, 1]
for i in range(2, n + 1):
    p.append((p[i - 2] + p[i - 1]) % 10007) 
    answer = p[i]
print(answer)

# 경우의 수 나열해보면 피보나치 수열