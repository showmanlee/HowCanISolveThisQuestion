// Shift Letter
// https://www.acmicpc.net/problem/6993

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		string s;
		int n;
		cin >> s >> n;
		cout << "Shifting " << s << " by " << n << " positions gives us: ";
		for (int i = 0; i < s.length(); i++) {
			cout << s[(i - n + s.length()) % s.length()];
		}
		cout << '\n';
	}
}

// 주어진 문자열을 오른쪽으로 n칸 돌린 결과 출력하기