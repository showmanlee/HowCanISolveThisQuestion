# 3의 배수
# https://www.acmicpc.net/problem/16561

n = int(input())
n = n // 3 - 2
answer = 0
for i in range(1, n + 1):
    answer += i
print(answer)

# 3 = 111
# 4 = 112 121 211
# 5 = 113 131 311 122 212 221
# 6 = 114 141 411 123 132 312 213 231 321 222
# 따라서 값은 1~(n/3-2)까지의 합
