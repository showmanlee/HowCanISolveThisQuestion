// 알파벳 뒤집기
// https://www.acmicpc.net/problem/30032

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, d;
    cin >> n >> d;
    vector<vector<char>> board(n, vector<char>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char t;
            cin >> t;
            if (t == 'b') {
                board[i][j] = (d == 1 ? 'p' : 'd');
            } else if (t == 'd') {
                board[i][j] = (d == 1 ? 'q' : 'b');
            } else if (t == 'p') {
                board[i][j] = (d == 1 ? 'b' : 'q');
            } else if (t == 'q') {
                board[i][j] = (d == 1 ? 'd' : 'p');
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j];
        }
        cout << '\n';
    }
}

// 상하좌우로 뒤집을 수 있는 n*n 배열의 소문자들을 상하/좌우로 두집을 때 결과 출력하기