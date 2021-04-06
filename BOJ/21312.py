# 홀짝 칵테일
# https://www.acmicpc.net/problem/21312

a, b, c = list(map(int, input().split()))
l = [a, b, c, a * b, a * c, b * c, a * b * c]
l.sort()
l.reverse()
flag = False
for i in l:
    if i % 2 == 1:
        flag = True
        print(i)
        break
if not flag:
    print(l[0])

# 서로 다른 번호가 있는 세 개의 음료를 하나 이상 써서 칵테일을 만드는데, 섞은 음료는 사용된 음료의 번호를 서로 곱한 값을 가지고, 짝수 보다는 홀수가 더 맛있고, 같은 짝수/홀수끼리는 번호가 높은 것이 더 맛있다. 만들 수 있는 칵테일 중 가장 맛있는 칵테일의 번호는?
# a, b, c, a * b, a * c, b * c, a * b * c를 한 배열에 넣어 역순으로 정렬한 후, 가장 높은 홀수가 존재하면 그걸 출력
# 만약 홀수가 없다면 모두 짝수만 있으니 해당 배열의 가장 높은 친구를 출력