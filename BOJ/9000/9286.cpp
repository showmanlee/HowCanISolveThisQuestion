// Gradabase
// https://www.acmicpc.net/problem/9286

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 1; t <= tt; t++) {
		int n;
		cin >> n;
		cout << "Case " << t << ":\n";
		for (int i = 0; i < n; i++) {
			int p;
			cin >> p;
			if (p < 6) {
				cout << p + 1 << '\n';
			}
		}
	}
}

// 6 미만의 수를 1 더해서 출력하기