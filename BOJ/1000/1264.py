# 모음의 개수
# https://www.acmicpc.net/problem/1264

while True:
    s = input()
    if s == '#':
        break
    count = 0
    for c in s:
        if c in ['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U']:
            count += 1
    print(count)

# 영어 문장에 나오는 모음의 수는?
