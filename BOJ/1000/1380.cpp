// 귀걸이
// https://www.acmicpc.net/problem/1380

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int num = 0;
	while (true) {
		num++;
		int n;
		cin >> n;
		if (n == 0) {
			break;
		}
		cin.ignore();
		vector<string> s(n + 1);
		vector<int> cnt(n + 1);
		for (int i = 1; i <= n; i++) {
			getline(cin, s[i]);
		}
		for (int i = 0; i < n * 2 - 1; i++) {
			char c;
			int p;
			cin >> p >> c;
			cnt[p]++;
		}
		for (int i = 1; i <= n; i++) {
			if (cnt[i] == 1) {
				cout << num << ' ' << s[i] << '\n';
			}
		}
	}
}

// 학생들의 이름과 귀걸이 압수/회수 현황이 주어질 때, 돌려받지 못한 1명 출력하기