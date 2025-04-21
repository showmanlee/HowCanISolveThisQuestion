// Fred’s Lotto Tickets
// https://www.acmicpc.net/problem/4118

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
		vector<bool> v(50);
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 6; j++) {
				int p;
				cin >> p;
				if (!v[p]) {
					cnt++;
				}
				v[p] = true;
			}
		}
		cout << (cnt == 49 ? "Yes" : "No") << '\n';
	}
}

// 주어지는 수열에서 1~49가 모두 나오는지 확인하기