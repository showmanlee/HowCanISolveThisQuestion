# 큰 수 계산
# https://www.acmicpc.net/problem/2408

n = int(input())
s = ''
for i in range(n + n - 1):
    s += input()
s = s.replace('/', '//')
print(eval(s))

# 계산기처럼 들어오는 순서대로 계산하는 게 아닌 전체 수식을 원래 순서에 맞게 계산해야 함
# 어려워 보이지만, python에는 eval이라고 문자열로 식을 주면 결과를 뱉는 함수가 있음
# 그래서 그걸 써먹어주면 됩니다 - /를 //로 바꾸어주는 것만 조심한다면