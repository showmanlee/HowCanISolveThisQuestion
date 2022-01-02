# 한글
# https://www.acmicpc.net/problem/11282

n = int(input())
print(chr(n + ord('가') - 1))

# 초/중/종성 순으로 정렬한 n번째 한글 출력하기
# 마침 유니코드에서도 한글이 그런 식으로 정렬되어 있음