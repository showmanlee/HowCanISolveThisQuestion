# 파도반 수열
# https://www.acmicpc.net/problem/9461

pad = [1, 1, 1]
for i in range(3, 100):
    pad.append(pad[i - 3] + pad[i - 2])
    
n = int(input())
for i in range(n):
    p = int(input())
    print(pad[p - 1])

# 전 숫자와 전전 숫자 대신 전전 숫자와 전전전 숫자를 더해서 내 위치에 저장하는 피보나치 수열
