// 좌석 배치도
// https://www.acmicpc.net/problem/30889

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<vector<char>> board(10, vector<char>(20, '.'));
    for (int i = 0; i < n; i++) {
        char c;
        int p;
        cin >> c >> p;
        board[c - 'A'][p - 1] = 'o';
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 20; j++) {
            cout << board[i][j];
        }
        cout << '\n';
    }
}

// 10열 20행 좌석이 놓인 극장에서 착석한 좌석 번호가 주어질 때, 착석 현황 출력하기

// 받아서 출력해주세요 