// Mines Motor Company
// https://www.acmicpc.net/problem/34309

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int res = 0;
	string prev;
	cin >> prev;
	for (int i = 1; i < n; i++) {
		string s;
		cin >> s;
		res += abs(s[0] - prev[0]) + abs(s[1] - prev[1]);
		prev = s;
	}
	cout << res << '\n';
}

// 알파벳으로 표현되는 2차원 격자에서 주어진 대로 움직일 때 이동하는 총 거리 구하기