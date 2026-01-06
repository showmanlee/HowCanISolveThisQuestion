// 생수병 놓기
// https://www.acmicpc.net/problem/34980

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	string s, t;
	cin >> s >> t;
	if (s == t) {
		cout << "Good" << '\n';
	} else {
		int a = 0, b = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == 'w') {
				a++;
			}
			if (t[i] == 'w') {
				b++;
			}
		}
		cout << (a == b ? "Its fine" : (a > b ? "Oryang" : "Manners maketh man")) << '\n';
	}
}

// w와 .로 구성된 두 문자열에서 w 개수의 변경여부 확인하기