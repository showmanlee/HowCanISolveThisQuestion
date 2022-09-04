// 주차의 신
// https://www.acmicpc.net/problem/5054

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		int n;
		cin >> n;
		int minn = 987654321, maxx = -987654321;
		for (int i = 0; i < n; i++) {
			int p;
			cin >> p;
			minn = min(minn, p);
			maxx = max(maxx, p);
		}
		int res = (maxx - minn) * 2;
		cout << res << '\n';
	}
}

// 1차원 공간의 모든 상점을 찍고 돌아오기 위해 차를 세울 때, 이동하게 되는 최소 거리는?

// 양 끝의 상점 사이에 차를 세우는 것이 가장 유리함 - 어쨌든 모든 상점을 찍기 위해서 양 끝점을 가야 하고, 한 번에 상점 하나만 가지 않아도 되므로
// 결과적으로 양 끝점 사이에서 출발해 양 끝점들을 찍고 돌아오는 것이므로 양 끝점 간의 길이 * 2가 됨