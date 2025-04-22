// 카드 바꿔치기
// https://www.acmicpc.net/problem/18766

#include <iostream>
#include <vector>
#include <string>
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
		vector<string> before(n), after(n);
		for (int i = 0; i < n; i++) {
			cin >> before[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> after[i];
		}
		sort(before.begin(), before.end());
		sort(after.begin(), after.end());
		bool res = true;
		for (int i = 0; i < n; i++) {
			if (before[i] != after[i]) {
				res = false;
				break;
			}
		}
		cout << (res ? "NOT " : "") << "CHEATER\n";
	}
}

// 두 문자열 배열의 원소가 모두 동일한지 판정하기