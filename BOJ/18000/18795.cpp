// 이동하기 3
// https://www.acmicpc.net/problem/18795

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    long long res = 0;
    for (int i = 0; i < n; i++) {
        long long p;
        cin >> p;
        res += p;
    }
    for (int i = 0; i < m; i++) {
        long long p;
        cin >> p;
        res += p;
    }
    cout << res << '\n';
}

// n+1*m*1 보드에서 좌측 상단에서 우측 하단으로 이동하는데 각 행/열 이동시 드는 비용이 주어질 때, 최소 비용 구하기

// 결국 모든 행/열을 한 번씩 들러야 하므로 모든 비용을 한 번씩 더해준다