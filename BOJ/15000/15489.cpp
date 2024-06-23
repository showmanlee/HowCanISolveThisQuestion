// 파스칼 삼각형
// https://www.acmicpc.net/problem/15489

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    vector<vector<int>> v(32, vector<int>(32));
    v[1][1] = 1;
    for (int i = 2; i <= 30; i++) {
        for (int j = 1; j <= i; j++) {
            v[i][j] = v[i - 1][j - 1] + v[i - 1][j];
        }
    }
    int r, c, w;
    cin >> r >> c >> w;
    int res = 0;
    for (int i = 0; i < w; i++) {
        for (int j = 0; j <= i; j++) {
            res += v[r + i][c + j];
        }
    }
    cout << res << '\n';
}

// 파스칼 삼각형에서 주어진 부분 정삼각형의 합 구하기

// 크기가 최대 30이므로 미리 구해놓고 풀 수 있음