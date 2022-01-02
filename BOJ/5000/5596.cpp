# 시험 점수
# https://www.acmicpc.net/problem/5596

a = list(map(int, input().split()))
b = list(map(int, input().split()))
if (sum(a) < sum(b)):
    print(sum(b))
else:
    print(sum(a))

# 두 사람의 시험 점수 합 중 큰 값 출력하기