// It’s Cold Here!
// https://www.acmicpc.net/problem/6830

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int res = 987654321;
	string ress;
	while (true) {
		string s;
		int n;
		cin >> s >> n;
		if (res > n) {
			res = n;
			ress = s;
		}
		if (s == "Waterloo") {
			break;
		}
	}
	cout << ress << '\n';
}

// 가장 추운 도시명 구하기