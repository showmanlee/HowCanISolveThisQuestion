// 유리구슬 (Glass Bead)
// https://www.acmicpc.net/problem/32281

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	string s;
	cin >> s;
	s += "0";
	long long res = 0;
	long long cnt = 0;
	for (char c : s) {
		if (c == '1') {
			cnt++;
		} else if (cnt != 0) {
			res += (cnt + 1) * cnt / 2;
			cnt = 0;
		}
	}
	cout << res << '\n';
}

// 피라미드 구조로 쌓이는 2차원 공간 내 1층이 주어질 때, 쌓아올려서 놓을 수 있는 최대 개수 구하기