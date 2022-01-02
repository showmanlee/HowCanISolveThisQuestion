# 고급 여관
# https://www.acmicpc.net/problem/12756

aa, ah = list(map(int, input().split()))
ba, bh = list(map(int, input().split()))
while ah > 0 and bh > 0:
    ah -= ba
    bh -= aa
if ah <= 0 and bh <= 0:
    print("DRAW")
elif ah <= 0:
    print("PLAYER B")
else:
    print("PLAYER A")

# 공격력과 생명력이 있는 카드 둘을 누가 죽을 때까지 서로 동시에 때리게 할 때, 이기는 쪽은?