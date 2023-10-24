// 기타리스트
// https://www.acmicpc.net/problem/1495

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, s, m;
    cin >> n >> s >> m;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    dp[0][s] = true;
    for (int i = 1; i <= n; i++) {
        int p;
        cin >> p;
        for (int j = 0; j <= m; j++) {
            if (dp[i - 1][j]) {
                if (j + p <= m) {
                    dp[i][j + p] = true;
                }
                if (j - p >= 0) {
                    dp[i][j - p] = true;
                }
            }
        }
    }
    bool pass = false;
    for (int j = m; j >= 0; j--) {
        if (dp[n][j]) {
            cout << j << '\n';
            pass = true;
            break;
        }
    }
    if (!pass) {
        cout << -1 << '\n';
    }
}

// 시작 볼륨, 다음 곡으로 넘어가면서 조절해야 하는 볼륨 폭(+-), 최대 볼륨이 주어질 때, 최대/최소 볼륨을 한 번도 넘기지 않고 마지막 곡에서 쓸 수 있는 최대 볼륨 구하기

// bfs보다는 dp - 곡 진행도 및 볼륨으로 2차원 dp를 만들 수 있음
// 게다가 범위 상 n^2로도 빠르게 dp를 짤 수 있다