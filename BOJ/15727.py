# 조별과제를 하려는데 조장이 사라졌다
# https://www.acmicpc.net/problem/15727

l = int(input())
t = l // 5
if l % 5 != 0:
    t += 1
print(t)

# 입력값을 받으면, ceil(l)을 출력하시오
