# 파일 옮기기
# https://www.acmicpc.net/problem/11943

aa, ab = list(map(int, input().split()))
ba, bb = list(map(int, input().split()))
print(min(aa + bb, ab + ba))

# 사과와 오렌지가 들어있는 두 바구니의 과일을 한 종류만 남기고 싶을 때 과일을 옮기는 최소 횟수는?
# (내 사과 + 저쪽 오렌지), (내 오렌지 + 저쪽 사과) 중 가장 작은 횟수