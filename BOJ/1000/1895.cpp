// 필터
// https://www.acmicpc.net/problem/1895

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n, m, t;
    cin >> n >> m;
    vector<vector<int>> board(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    cin >> t;
    int res = 0;
    for (int i = 0; i < n - 2; i++) {
        for (int j = 0; j < m - 2; j++) {
            vector<int> v;
            for (int x = i; x < i + 3; x++) {
                for (int y = j; y < j + 3; y++) {
                    v.push_back(board[x][y]);
                }
            }
            sort(v.begin(), v.end());
            if (v[4] >= t) {
                res++;
            }
        }
    }
    cout << res << '\n';
}

// n*m 보드에서 3*3 필터의 중간값들을 구할 때, 중간값 결과 중 t 이상인 개수 구하기