// 이진수 덧셈
// https://www.acmicpc.net/problem/2729

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
		string a, b;
		cin >> a >> b;
		int jmp = 0;
		string res;
		while (!a.empty() && !b.empty()) {
			int p = (a.back() - '0') + (b.back() - '0') + jmp;
			a.pop_back();
			b.pop_back();
			res = to_string(p % 2) + res;
			jmp = p / 2;
		}
		while (!a.empty()) {
			int p = (a.back() - '0') + jmp;
			a.pop_back();
			res = to_string(p % 2) + res;
			jmp = p / 2;
		}
		while (!b.empty()) {
			int p = (b.back() - '0') + jmp;
			b.pop_back();
			res = to_string(p % 2) + res;
			jmp = p / 2;
		}
		if (jmp == 1)
			res = '1' + res;
		while (res.front() == '0')
			res = res.substr(1);
		if (res == "")
			res = "0";
		cout << res << '\n';
	}
}

// 두 이진수 더하기

// 맨 끝의 두 수, 그리고 받아올리는 수를 이용하여 뒤에서부터 계산해주면 ok - string을 스택 삼아
// 피연산자가 80자리가 나올 수 있기에 정수형으로 변환하는 것은 불가능
// 피연산자는 앞에 0이 붙을 수 있지만, 결과는 0이 붙으면 안됨에 주의 - 결과가 0인 경우도 생각하기