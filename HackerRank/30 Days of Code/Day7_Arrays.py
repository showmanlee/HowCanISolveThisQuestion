# Day 7: Arrays
# https://www.hackerrank.com/challenges/30-arrays/problem

if __name__ == '__main__':
    n = int(input())
    arr = list(map(int, input().rstrip().split()))
    for i in range(len(arr) - 1, -1, -1):
        print(arr[i], end=" ")

# 오늘은 배열
# 배열 숫자 받아서 거꾸로 출력하기