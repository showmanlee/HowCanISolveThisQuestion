// 지름길
// https://www.acmicpc.net/problem/1446

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n, d;
    cin >> n >> d;
    vector<int> dp(d + 1);
    for (int i = 0; i <= d; i++) {
        dp[i] = i;
    }
    vector<vector<pr>> board(d + 1);
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (b <= d) {
            board[b].push_back({a, c});
        }
    }
    for (int i = 1; i <= d; i++) {
        dp[i] = min(dp[i], dp[i - 1] + 1);
        for (pr p : board[i]) {
            dp[i] = min(dp[i], dp[p.first] + p.second);
        }
    }
    cout << dp[d] << '\n';
}

// 출발지부터 도착지까지 이동하기 위해 고속도로를 그대로 타거나 지름길을 탈 수 있을 때, 도착지까지 이동하는 최소 이동 거리는?

// dp로 1~d까지 깔아두고, 순서대로 돌면서 dp를 갱신시킨다
// 기본적으로 바로 전칸 + 1, 만약 지름길 도착지라면 해당 지름길 시작점 + 지름길 거리 중 가장 작은 값을 dp로 기록
// 이렇게 dp를 차례로 갱신하여 마지막칸 dp 값 출력하기
// 한 지점에 지름길이 여러 개일 수 있으므로 지름길은 2중 vector + pair로 관리
// 지름길 도착 지점이 d 이상으로 주어질 수 있음에 주의 - 이 경우 해당 지름길은 버려야 함