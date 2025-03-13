// 팔
// https://www.acmicpc.net/problem/1105

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string a, b;
	cin >> a >> b;
	int res = 0;
	if (a.length() == b.length()) {
		for (int i = 0; i < a.length(); i++) {
			if (a[i] == '8' && b[i] == '8') {
				res++;
			} else {
				break;
			}
		}
	}
	cout << res << '\n';
}

// 두 정수 이상/이하의 정수 중 8이 가장 적게 들어가는 수의 8 개수 구하기