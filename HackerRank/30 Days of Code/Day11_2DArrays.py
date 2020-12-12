# Day 11: 2D Arrays
# https://www.hackerrank.com/challenges/30-2d-arrays/problem

if __name__ == '__main__':
    arr = []

    for _ in range(6):
        arr.append(list(map(int, input().rstrip().split())))
        
    maxi = -80
    for i in range(4):
        for j in range(4):
            summ = arr[i][j] + arr[i][j+1] + arr[i][j+2] + arr[i+1][j+1] + arr[i+2][j] + arr[i+2][j+1] + arr[i+2][j+2]
            if maxi < summ:
                maxi = summ
    print(maxi)


# 6x6 배열에서 나오는 3x3 모래시계 모양의 합 중 최댓값 구하기
# 음수가 나올 수 있음에 주의