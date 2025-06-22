// Periods
// https://www.acmicpc.net/problem/26560

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++) {
		string s;
		getline(cin, s);
		if (s.back() != '.') {
			s += '.';
		}
		cout << s << '\n';
	}
}

// 주어진 문장에 마침표 없으면 찍고 출력하기