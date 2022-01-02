# solved.ac
# https://www.acmicpc.net/problem/18110

import sys

n = int(sys.stdin.readline())
level = []
for i in range(n):
    level.append(int(sys.stdin.readline()))
res = 0
if n != 0:
    level.sort()
    p = int(n * 0.15 + 0.5)
    if p != 0:
        res = sum(level[p:-p]) / len(level[p:-p])
    else:
        res = sum(level) / len(level)
    res = int(res + 0.5)
print(res)

# 기여된 모든 난이도를 30% 절사평균(상위/하위 15% 제외 평균)낸 값은(반올림)?
# 받은 값들을 정렬한 후, 15% 값(반올림)을 구해 그 앞과 뒤를 자른 배열의 평균을 구한다...
# 받는 값이 아예 없을 수도 있고, 평균 내는 중 0으로 나눌 수 있음에 주의
# input 값 많으니까 sys로 입력 받아주고...
