// Nonogramm
// https://www.acmicpc.net/problem/7168

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<vector<char>> board(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        vector<int> v;
        int cnt = 0;
        for (int j = 0; j < m; j++) {
            if (board[i][j] == '#') {
                cnt++;
            } else if (cnt != 0) {
                v.push_back(cnt);
                cnt = 0;
            }
        }
        if (cnt != 0) {
            v.push_back(cnt);
        } else if (v.empty()) {
            v.push_back(cnt);
        }
        for (int i : v) {
            cout << i << ' ';
        }
        cout << '\n';
    }
    for (int j = 0; j < m; j++) {
        vector<int> v;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (board[i][j] == '#') {
                cnt++;
            } else if (cnt != 0) {
                v.push_back(cnt);
                cnt = 0;
            }
        }
        if (cnt != 0) {
            v.push_back(cnt);
        } else if (v.empty()) {
            v.push_back(cnt);
        }
        for (int i : v) {
            cout << i << ' ';
        }
        cout << '\n';
    }
}

// 노노그램 판이 주어질 때, 각 열/행에 들어가는 수들 출력하기

// n*m 보드를 받은 후, x/y의 원소들 순회하며 연속되는 덩어리들 세주기
// 아무것도 없는 줄 처리에 주의