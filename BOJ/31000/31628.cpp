// 가지 한 두름 주세요
// https://www.acmicpc.net/problem/31628

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    vector<vector<string>> board(10, vector<string>(10));
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> board[i][j];
        }
    }
    int res = 0;
    for (int i = 0; i < 10; i++) {
        int r = 1;
        string s = board[i][0];
        for (int j = 1; j < 10; j++) {
            if (board[i][j] != s) {
                r = 0;
                break;
            }
        }
        if (r == 1) {
            res = 1;
            break;
        }
        s = board[0][i];
        r = 1;
        for (int j = 1; j < 10; j++) {
            if (board[j][i] != s) {
                r = 0;
                break;
            }
        }
        if (r == 1) {
            res = 1;
            break;
        }
    }
    cout << res << '\n';
}

// 10*10 보드에서 한 줄이 모두 같은 경우가 있는지 확인하기