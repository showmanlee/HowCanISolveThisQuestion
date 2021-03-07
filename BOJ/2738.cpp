// 행렬 덧셈
// https://www.acmicpc.net/problem/2738

#include <iostream>
#include <vector>
using namespace std;

int main(void){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m)), b(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> b[i][j];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << (a[i][j] + b[i][j]) << ' ';
        cout << '\n';
    }
}

// 크기가 같은 두 행렬 더하기
// A[i,j] + B[i,j]