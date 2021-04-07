// 지속
// https://www.acmicpc.net/problem/11648

#include <iostream>
#include <string>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	cin >> s;
	int cnt = 0;
	while (true) {
		if (s.length() == 1) {
			cout << cnt << '\n';
			break;
		}
		int p = 1;
		for (char c : s)
			p *= c - '0';
		s = to_string(p);
		cnt++;
	}
}

// 정수의 각 자릿수를 모두 곱하는 과정을 반복할 때 한자릿수가 되려면 몇 번 반복해야 하는가?
// 정수를 문자열로 만들어서 곱하는 과정을 반복
// 물론 들어오는 정수가 처음부터 한자릿수일 수 있으니 판정은 처음부터