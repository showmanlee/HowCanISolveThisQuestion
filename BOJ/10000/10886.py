# 0 = not cute / 1 = cute
# https://www.acmicpc.net/problem/10886

n = int(input())
p = 0
for i in range(n):
    p += int(input())
if p > (n / 2):
    print("Junhee is cute!")
else:
    print("Junhee is not cute!")

# 1이 더 많이 나오면 귀여운 거래
# 나온 1을 모두 더해서 n의 절반보다 더 많이 나오면 귀여운 걸로 하자