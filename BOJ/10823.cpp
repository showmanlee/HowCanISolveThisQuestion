// 더하기
// https://www.acmicpc.net/problem/10823

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s, comp;
	while (cin >> s) {
		comp += s;
	}
	string p;
	int res = 0;
	for (char c : comp) {
		if (c == ',') {
			res += stoi(p);
			p = "";
		}
		else {
			p += c;
		}
	}
	res += stoi(p);
	cout << res << '\n';
}

// 여러 줄에 걸쳐 주어지는 숫자와 ,로 구성된 문자열을 한 줄로 만들어 ,로 나누어진 정수를 모두 더한 결과 출력하기

// 주어진 문자열을 한줄씩 받아 모두 합치고, 합친 문자열에서 숫자들을 뽑아내 더해서 출력한다