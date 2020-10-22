# 등굣길
# https://programmers.co.kr/learn/courses/30/lessons/42898

def solution(m, n, puddles):
    answer = 0
    dp = [[0 for i in range(n + 1)] for i in range(m + 1)]
    for v in puddles:
        dp[v[0]][v[1]] = -1
        
    dp[1][0] = 1
    for i in range(1, m + 1):
        for j in range(1, n + 1):
            if [i, j] in puddles:
                dp[i][j] = 0
            else:
                dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % 1000000007
    answer = dp[m][n] 
    return answer

# 2차원 배열을 사용한 dp 문제 - 가능한 길 수를 각 칸에 저장하고, 웅덩이는 못 가니까 0으로 처리
# 2차원 배열을 1~n, 1~m까지 순회하면서 숫자를 채우는데, 0인 항들은 테두리 부분을 1로 채워주는 역할을 한다
# 단, 처음에 1로 채우기 위해 [1][0] 또는 [0][1]에 1을 채워서 [1][1]에 0이 채워질 수 있도록 처리