// /gg
// https://www.acmicpc.net/problem/34032

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int res = 0;
	for (int i = 0; i < n; i++) {
		char c;
		cin >> c;
		if (c == 'O') {
			res++;
		}
	}
	cout << ((n + 1) / 2 <= res ? "Yes" : "No") << '\n';
}

// n명 중 절반 이상이 O를 입력했는지 구하기