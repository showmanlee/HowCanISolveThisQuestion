# 타일 장식물
# https://www.acmicpc.net/problem/13301

n = int(input())
pib = [1, 1]
for i in range(2, n + 1):
    pib.append(pib[i - 2] + pib[i - 1])
print(pib[n - 1] * 2 + pib[n] * 2)

# 황금비 모양으로 n개의 타일을 이어붙인 모양의 둘레 구하기
# 긴 면은 마지막 타일 + 그 전 타일(= 다음 타일), 짧은 면은 마지막 타일
# 타일 개수가 1개일 경우에 주의
