// 틱택토 이기기
// https://www.acmicpc.net/problem/9290

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) {
        vector<vector<char>> board(3, vector<char>(3));
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cin >> board[i][j];
            }
        }
        char c;
        cin >> c;
        vector<int> v(8);
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                v[j] += (board[i][j] == c ? 1 : 0);
                v[j + 3] += (board[j][i] == c ? 1 : 0);
            }
            v[6] += (board[i][i] == c ? 1 : 0);
            v[7] += (board[i][2 - i] == c ? 1 : 0);
        }
        cout << "Case " << t << ":\n";
        for (int p = 0; p < 8; p++) {
            if (v[p] == 2) {
                for (int i = 0; i < 3; i++) {
                    if (p < 3) {
                        if (board[i][p] == '-') {
                            board[i][p] = c;
                        }
                    } else if (p < 6) {
                        if (board[p - 3][i] == '-') {
                            board[p - 3][i] = c;
                        }
                    } else if (p == 6) {
                        if (board[i][i] == '-') {
                            board[i][i] = c;
                        }
                    } else if (p == 7) {
                        if (board[i][2 - i] == '-') {
                            board[i][2 - i] = c;
                        }
                    }
                }
                break;
            }
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << board[i][j];
            }
            cout << '\n';
        }
    }
}

// 틱택토의 마지막 턴과 말이 주어질 때, 최종적으로 승리한 판 출력하기

// 빈칸, 각 줄에 그려진 내 말 개수를 보고 그릴 위치 골라서 그린다