# 2 番目に大きい整数
# https://www.acmicpc.net/problem/20976

p = list(map(int, input().split()))
p.sort()
print(p[1])

# 세 수 중 중간값 출력하기