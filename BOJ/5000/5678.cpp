// Bakugan
// https://www.acmicpc.net/problem/5678

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	while (true) {
		int n;
		cin >> n;
		if (n == 0) {
			break;
		}
		vector<int> m(n + 1), l(n + 1);
		int mm = 0, ll = 0;
		for (int i = 1; i <= n; i++) {
			cin >> m[i];
			mm += m[i];
		}
		for (int i = 1; i <= n; i++) {
			cin >> l[i];
			ll += l[i];
		}
		int mc = 0, lc = 0;
		bool bonus = true;
		for (int i = 1; i <= n; i++) {
			if (m[i] == m[i - 1]) {
				mc++;
			} else {
				mc = 1;
			}
			if (l[i] == l[i - 1]) {
				lc++;
			} else {
				lc = 1;
			}
			if (bonus) {
				if (mc >= 3 && lc >= 3) {
					bonus = false;
				} else if (mc >= 3) {
					mm += 30;
					bonus = false;
				} else if (lc >= 3) {
					ll += 30;
					bonus = false;
				}
			}
		}
		cout << (mm > ll ? "M" : (mm < ll ? "L" : "T")) << '\n';
	}
}

// 1부터 10까지 내서 모두 더하는 게임에서 연속으로 3번 숫자를 가장 먼저 내면 30점을 얻을 때, 결과 출력하기