# 킹, 퀸, 룩, 비숍, 나이트, 폰
# https://www.acmicpc.net/problem/3003

a = list(map(int, input().split()))
b = [1, 1, 2, 2, 2, 8]
for i in range(6):
    print(b[i] - a[i], end = ' ')

# 추가로 넣고 빼야 할 체스 말 개수 구하
