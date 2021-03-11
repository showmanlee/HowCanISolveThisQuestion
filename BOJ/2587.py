# 대표값2
# https://www.acmicpc.net/problem/2587

arr = [0,0,0,0,0]
for i in range(5):
    arr[i] = int(input())
arr.sort()
print(sum(arr) // 5)
print(arr[2])

# 5개의 자연수의 평균과 중앙값 출력하기
