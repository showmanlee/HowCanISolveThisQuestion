// 팩토리얼 진법
// https://www.acmicpc.net/problem/5692

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	while (true) {
		string s;
		cin >> s;
		if (s == "0") {
			break;
		}
		int p = 1, ctr = 1;
		int res = 0;
		while (!s.empty()) {
			res += p * (s.back() - '0');
			p *= ++ctr;
			s.pop_back();
		}
		cout << res << '\n';
	}
}

// i번 자리의 값을 숫자 * i!로 계산하는 팩토리얼 진법 수가 주어졌을 때, 십진수로 변환하기

// 뒤에서부터 진법 전환하듯이 구하면 됩니다...