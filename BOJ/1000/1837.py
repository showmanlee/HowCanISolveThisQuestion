# 암호제작
# https://www.acmicpc.net/problem/1837

p, k = map(int, input().split())
flag = True
for i in range(2, k):
    if p % i == 0:
        print("BAD", i)
        flag = False
        break
if flag:
    print("GOOD")

# 두 소수의 곱으로 구성된 암호와 k가 주어질 때, 암호를 구성하는 두 소수 중 k보다 작은 소수가 있는지 판정하기
# 암호는 10^100까지 주어질 수 있으므로 쉬운 계산을 위해 파이썬으로
# k는 100만까지 주어질 수 있으므로 