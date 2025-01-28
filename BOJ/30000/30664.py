# Loteria Falha
# https://www.acmicpc.net/problem/30664

while True:
    n = int(input())
    if n == 0:
        break
    if n % 42 == 0:
        print("PREMIADO")
    else:
        print("TENTE NOVAMENTE")

# 주어진 수가 42의 배수인지 판정하기