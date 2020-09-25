# Papier kamień nożyczki
# https://www.acmicpc.net/problem/8806

n = int(input())
for i in range(n):
    adam = input().split()
    gosia = input().split()
    prob = 0
    for p in range(0, 3):
        prob += float(adam[p]) * float(gosia[(p + 1) % 3]) - float(adam[p]) * float(gosia[(p + 2) % 3])
    if prob == 0:
        print("=")
    elif prob > 0:
        print("ADAM")
    else:
        print("GOSIA")          
    
# 대충 가위바위보 낼 확률로 이길 사람 구하라는 뜻
# ADAM vs GOSIA의 대결, 테케 중 첫 줄은 A가 보, 바위, 가위를 낼 확률, 둘째 줄은 G가 그럴 확률
# 인덱스가 같으면 무승부, +1이면 승리, +2면 패배