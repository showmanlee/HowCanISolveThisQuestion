# 검증수
# https://www.acmicpc.net/problem/2475

n = list(map(int, input().split()))
m = 0
for i in n:
    m += i ** 2
print(m % 10)

# solved.ac CLASS 1 올클!
# 다른 클래스도 그렇게 달려나가겠습니다
# 목표의식 갖게하는 solved.ac 만세!
