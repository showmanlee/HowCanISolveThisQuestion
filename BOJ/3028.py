# 창영마을
# https://www.acmicpc.net/problem/3028

s = input()
a = [True, False, False]
for c in s:
    if c == 'A':
        a[0], a[1] = a[1], a[0]
    elif c == 'B':
        a[1], a[2] = a[2], a[1]
    elif c == 'C':
        a[0], a[2] = a[2], a[0]
for i in range(3):
    if a[i]:
        print(i + 1)

# 야바위에서 섞은 순서가 주어질 때 공이 있는 컵의 위치는?
# 제일 왼쪽 컵부터 시
