# Darius님 한타 안 함?
# https://www.acmicpc.net/problem/20499

k, d, a = list(map(int, input().split('/')))
if d == 0 or k + a < d:
    print("hasu")
else:
    print("gosu")

# 이기더라도 데스 생기면 안 되고 KDA를 중요시하는 우리팀 다리가 진짜 고수인가?
# 조건식이 문제에 나와있네요
