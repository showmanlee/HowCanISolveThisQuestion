// Таблица результатов
// https://www.acmicpc.net/problem/28808

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	int res = 0;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (char c : s) {
			if (c == '+') {
				res++;
				break;
			}
		}
	}
	cout << res << '\n';
}

// 주어진 문자열들에서 +가 있는 문자열 개수 구하기