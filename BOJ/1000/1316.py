# 그룹 단어 체커
# https://www.acmicpc.net/problem/1316

n = int(input())
count = 0
for i in range(n):
    s = input()
    p = []
    t = True
    for c in s:
        if c in p:
            if c != p[-1]:
                t = False
                break
        else:
            p.append(c)
    if t:
        count += 1
print(count)

# 문자열의 글자들이 두 파트 이상에 걸쳐 나오지 않는다면 통과
