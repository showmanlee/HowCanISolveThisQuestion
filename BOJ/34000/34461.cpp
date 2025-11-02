// 고령 멜빙 축제
// https://www.acmicpc.net/problem/34661

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		int n, m;
		cin >> n >> m;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				char c;
				cin >> c;
				if (c == '.') {
					cnt++;
				}
			}
		}
		cout << (cnt % 2 == 1 ? "sewon" : "pizza") << '\n';
	}
}

// 1*1, 3*3 블럭으로 채우기 게임을 할 때, 이기는 사람 구하기