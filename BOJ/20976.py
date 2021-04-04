# 2 番目に大きい整数
# https://www.acmicpc.net/problem/20976

p = list(map(int, input().split()))
p.sort()
print(p[1])

# 세 개의 숫자 중 중간값 구하기
# 정렬 후 중간 뽑기