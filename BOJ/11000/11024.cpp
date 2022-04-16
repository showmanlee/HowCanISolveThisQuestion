// 더하기 4
// https://www.acmicpc.net/problem/11024

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string n;
	getline(cin, n);
	for (int t = 0; t < stoi(n); t++) {
		string s;
		getline(cin, s);
		stringstream ss(s);
		int res = 0, p = 0;
		while (ss >> p) {
			res += p;
		}
		cout << res << '\n';
	}
}

// 한 줄에 공백을 두고 주어지는 수들의 합 구하기

// stringstream