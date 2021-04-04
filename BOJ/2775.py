# 부녀회장이 될테야
# https://www.acmicpc.net/problem/2775

build = [[0,1,2,3,4,5,6,7,8,9,10,11,12,13,14]]
for i in range(1, 15):
    build.append([])
    for j in range(0, 15):
        t = sum(build[i-1][:j+1])
        build[i].append(t)
n = int(input())
for i in range(n):
    p = int(input())
    q = int(input())
    print(build[p][q])

# 건물 x층의 y호에 사는 사람들은 한 층 아래의 1~y호에 사는 사람의 합만큼을 데리고 살아야 한다
# 여기서 0층의 y호 사람은 y명 산다고 가정
# 그렇담 101호 사람은 1명, 102호 사람은 1+2명, 103호 사람은 1+2+3명
# 그리고 201호 사람은 1명, 202호 사람은 1+(1+2)명, 203호 사람은 1+(1+2)+(1+2+3)명...
# 어쨌든 이런 식으로 나아가니까 dp로 적어서 풀이
