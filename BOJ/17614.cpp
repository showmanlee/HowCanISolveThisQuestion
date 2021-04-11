// 369
// https://www.acmicpc.net/problem/17614

#include <iostream>
#include <string>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int res = 0;
	for (int i = 1; i <= n; i++) {
		string s = to_string(i);
		for (char c : s)
			if (c == '3' || c == '6' || c == '9')
				res++;
	}
	cout << res << '\n';
}

// 369 게임에서 n까지 게임을 진행할 때 치게되는 박수 수는?
// 다행스럽게도 각 자릿수를 따로 보면서 369가 나오면 추가하는 방식이 먹힘