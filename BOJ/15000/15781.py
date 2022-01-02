# 헬멧과 조끼
# https://www.acmicpc.net/problem/15781

n, m = list(map(int, input().split()))
head = list(map(int, input().split()))
armor = list(map(int, input().split()))
print(max(head) + max(armor))

# 헬멧과 조끼로 얻을 수 있는 방어력의 최대는?
# 헬멧에서 최고 + 조끼에서 최고