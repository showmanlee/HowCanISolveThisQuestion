# 나는 요리사다
# https://www.acmicpc.net/problem/2953

result = []
for i in range(5):
    score = list(map(int, input().split()))
    result.append(sum(score))
print(result.index(max(result)) + 1, max(result))