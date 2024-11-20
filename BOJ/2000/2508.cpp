// 사탕 박사 고창영
// https://www.acmicpc.net/problem/2508

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int tt;
    cin >> tt;
    for (int t = 0; t < tt; t++) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> board(n, vector<char>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> board[i][j];
            }
        }
        int res = 0;
        for (int i = 0; i < n - 2; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'v' && board[i + 1][j] == 'o' && board[i + 2][j] == '^') {
                    res++;
                }
            }
        } 
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m - 2; j++) {
                if (board[i][j] == '>' && board[i][j + 1] == 'o' && board[i][j + 2] == '<') {
                    res++;
                }
            }
        }
        cout << res << '\n';
    }
}

// n*m 문자열 보드에서 >o< 나 v 케이스 개수 구하기
//                        o
//                        ^