# 뉴비의 기준은 뭘까?
# https://www.acmicpc.net/problem/19944

n, m = list(map(int, input().split()))
if m <= 2:
    print("NEWBIE!")
elif m <= n:
    print("OLDBIE!")
else:
    print("TLE!")

# 2학년 이하면 뉴비, n학년 이하면 올드비, 그보다 많으면 틀딱일 때 판정하기