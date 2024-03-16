# A/B - 3
# https://www.acmicpc.net/problem/16428

a, b = list(map(int, input().split()))
if B > 0:
    print(a // b)
    print(a % b)
else:
    print(-(a // -b))
    print(a % -b)

# A / B의 몫과 나머지 구하기
# 음수가 나오는 경우도 대비해줘야 함 - python floor 이슈?