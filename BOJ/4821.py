# 페이지 세기
# https://www.acmicpc.net/problem/4821

while True:
    n = int(input())
    if n == 0:
        break
    s = input()
    checked = [False for i in range(n + 1)]
    for p in s.split(','):
        if '-' in p:
            sa, sb = p.split('-')
            a = int(sa)
            b = int(sb)
            if a <= b:
                for i in range(a, b + 1, 1):
                    if i > n:
                        break
                    checked[i] = True
        else:
            if int(p) <= n:
                checked[int(p)] = True
    res = checked.count(True)
    print(res)
        
# 인쇄할 페이지 범위가 주어졌을 때, 실제로 인쇄되는 페이지의 수는?

# 범위가 겹치는 페이지는 한 번만 출력되고, 페이지 범위를 벗어나면 해당 페이지는 출력되지 않는다
# 때문에 출력되는 페이지 여부를 배열로 판정하면 중복 없이 체크할 수 있음
# 편한 파싱을 위해 오랜만에 python 사용하기
