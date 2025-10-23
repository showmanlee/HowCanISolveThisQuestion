// Bad Directions
// https://www.acmicpc.net/problem/34447

#include <iostream>
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
		string s;
		cin >> n >> s;
		for (char& c : s) {
			int p = c - '0';
			p = (p + n) % 10;
			c = p + '0';
		}
		cout << s << '\n';
	}
}

// 주어진 수의 각 자리에 n 더해서 1의 자리만 남긴 결과 출력하기