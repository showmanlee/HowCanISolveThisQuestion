// 5와 6의 차이
// https://www.acmicpc.net/submit/2864

#include <iostream>
#include <string>
using namespace std;

int translate(string s, bool mode) {
	for (int i = 0; i < s.length(); i++) {
		if (mode && s[i] == '5')
			s[i] = '6';
		else if (!mode && s[i] == '6')
			s[i] = '5';
	}
	return stoi(s);
}

int main(void) {
	string a, b;
	cin >> a >> b;
	cout << (translate(a, false) + translate(b, false)) << ' ' << (translate(a, true) + translate(b, true)) << '\n';
}

// 5와 6이 헷갈리는 상황에서 두 수가 주어졌을 때 두 수의 합의 최솟값과 최댓값은?
// 최소는 무조건 5, 최대는 무조건 6으로 변환
// 문자열로 받아 변환변환	