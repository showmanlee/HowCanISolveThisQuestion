# 긴급 회의
# https://www.acmicpc.net/problem/20113

n = int(input())
vote = [0 for i in range(n + 1)]
p = list(map(int, input().split()))
for i in p:
    vote[i] += 1
vote[0] = 0
if max(vote) == 0 or vote.count(max(vote)) >= 2:
    print("skipped")
else:
    print(vote.index(max(vote)))

# 가장 많은 표를 받은 *단 한 명*의 임포스터는 누구?
