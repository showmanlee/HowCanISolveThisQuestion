// Rain Diary
// https://www.acmicpc.net/problem/27182

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
	if (n > 7) {
		res = n - 7;
	} else {
		res = m + 7;
	}
	cout << res << '\n';
}

// 오늘과 14일 전 날짜가 주어질 때, 7일 전 날짜 구하기