// Happy Number
// https://www.acmicpc.net/problem/14954

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	string s = to_string(n);
	map<int, bool> visit;
	while (true) {
		int p = 0;
		for (char c : s) {
			p += (c - '0') * (c - '0');
		}
		if (p == 1) {
			cout << "HAPPY\n";
			break;
		} else if (visit[p]) {
			cout << "UNHAPPY\n";
			break;
		} else {
			s = to_string(p);
		}
		visit[p] = true;
	}
}

// 어떤 수의 자릿수를 제곱한 것을 합친 함수를 돌릴 떄, 1로 수렴하는지 구하기