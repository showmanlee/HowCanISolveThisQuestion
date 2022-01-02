# 잃어버린 괄호
# https://www.acmicpc.net/problem/1541

minus = input().split('-')
plus = []
for s in minus:
    p = list(map(int, s.split('+')))
    plus.append(sum(p))
res = plus[0]
for i in range(1, len(plus)):
    res -= plus[i]
print(res)

# 덧셈과 뺄셈만 있는 수식에서 적절히 괄호를 쳐서 결과값이 최소가 되도록 만들기
# 덧셈끼리 괄호로 묶어 그것들끼리 빼면 최솟값이 나온다
# '-'을 기준으로 split 후 '+'을 기준으로 split해 더하고 빼기
