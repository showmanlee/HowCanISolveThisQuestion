// Reverse
// https://www.acmicpc.net/problem/26546

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		string s;
		cin >> s;
		int a, b;
		cin >> a >> b;
		for (int i = 0; i < s.length(); i++) {
			if (i >= a && i < b) {
				continue;
			}
			cout << s[i];
		}
		cout << '\n';
	}
}

// 문자열에서 a 이상 b 미만의 인덱스 빼고 출력하기

// 그냥 출력해봅시다 - 반복문 돌려가며...