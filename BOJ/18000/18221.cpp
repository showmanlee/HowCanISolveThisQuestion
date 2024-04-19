// 교수님 저는 취업할래요
// https://www.acmicpc.net/problem/18221

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<vector<int>> board(n, vector<int>(n));
    int sx, sy, dx, dy;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            if (board[i][j] == 2) {
                sx = i;
                sy = j;
            }
            if (board[i][j] == 5) {
                dx = i;
                dy = j;
            }
        }
    }
    int res = 0;
    double dist = sqrt(pow(sx - dx, 2) + pow(sy - dy, 2));
    if (dist >= 5.0) {
        int cnt = 0;
        for (int i = min(sx, dx); i <= max(sx, dx); i++) {
            for (int j = min(sy, dy); j <= max(sy, dy); j++) {
                if (board[i][j] == 1) {
                    cnt++;
                }
            }
        }
        if (cnt >= 3) {
            res = 1;
        }
    }
    cout << res << '\n';
}

// n*n 보드에서 2와 5의 거리가 5 이상이면서 2와 5를 꼭짓점으로 하는 축에 평행한 직사각형에 1이 3개 이상 들어가는지 확인하기

// 보드 받아서 계산해보기