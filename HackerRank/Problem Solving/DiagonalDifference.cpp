// Diagonal Difference
// https://www.hackerrank.com/challenges/diagonal-difference/problem

int diagonalDifference(vector<vector<int>> arr) {
    int n = arr.size();
    int a = 0, b = 0;
    for (int i = 0; i < n; i++){
        a += arr[i][i];
        b += arr[i][n - 1 - i];
    }
    return abs(a - b);
}

// 정사각형 행렬의 두 대각선 상의 있는 수들의 합의 차의 절댓값
