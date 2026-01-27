// Digits
// https://www.acmicpc.net/problem/4176

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	while (true) {
		string s;
		cin >> s;
		if (s == "END") {
			break;
		}
		int res = 1;
		while (s != "1") {
			s = to_string(s.length());
			res++;
		}
		cout << res << '\n';
	}
}

// 정수 수열 시작이 주어질 때, 길이를 정수로 변환하는 식으로 해서 맞붙은 항이 같아지는 타이밍 구하기