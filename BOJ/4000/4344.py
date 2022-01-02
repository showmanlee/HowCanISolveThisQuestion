# 평균은 넘겠지
# https://www.acmicpc.net/problem/4344.

n = int(input())
for i in range(n):
    score = input().split()[1:]
    result = 0
    for c in score:
        result += int(c)
    result /= len(score)
    p = 0
    for c in score:
        if int(c) > result:
            p += 1
    print("{:.3f}%".format(p / len(score) * 100))
