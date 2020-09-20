# 첼시를 도와줘!
# https://www.acmicpc.net/problem/11098

n = int(input())
for i in range(n):
    players = []
    p = int(input())
    for j in range(p):
        prise, name = input().split()
        players.append([int(prise), name])
    players.sort(key = lambda x : x[0], reverse=True)
    print(players[0][1])
