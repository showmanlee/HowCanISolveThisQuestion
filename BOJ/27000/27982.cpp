// 큐브 더미
// https://www.acmicpc.net/problem/27982

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<vector<vector<bool>>> v(n + 1, vector<vector<bool>>(n + 1, vector<bool>(n + 1)));
    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        v[x][y][z] = true;
    }
    int res = 0;
    for (int i = 2; i <= n - 1; i++) {
        for (int j = 2; j <= n - 1; j++) {
            for (int k = 2; k <= n - 1; k++) {
                if (v[i][j][k] && v[i + 1][j][k] && v[i - 1][j][k] && v[i][j + 1][k] && v[i][j - 1][k] && v[i][j][k + 1] && v[i][j][k - 1]) {
                    res++;
                }
            }
        }
    }
    cout << res << '\n';
}

// n*n*n 보드의 각 칸에 큐브가 있을 때, 큐브가 있는 칸의 상하좌우전후 칸 모두에 큐브가 있는 경우의 수 출력하기

// 범위가 작으므로 직접 돌아봅시다