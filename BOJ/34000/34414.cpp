// Tall Enough
// https://www.acmicpc.net/problem/34414

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	bool res = true;
	for (int i = 0; i < n; i++) {
		int p;
		cin >> p;
		if (p < 48) {
			res = false;
		}
	}
	cout << (res ? "True" : "False") << '\n';
}

// 주어진 대문자 문자열에서 모든 알파벳이 있는지 확인하고, 없다면 없는 거 출력하기