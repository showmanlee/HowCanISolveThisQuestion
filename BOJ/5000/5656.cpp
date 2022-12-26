// 비교 연산자
// https://www.acmicpc.net/problem/5656

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n = 1;
	while (true) {
		string o;
		int a, b;
		cin >> a >> o >> b;
		if (o == "E") {
			break;
		}
		cout << "Case " << n << ": ";
		if (o == ">") {
			cout << (a > b ? "true" : "false");
		} else if (o == ">=") {
			cout << (a >= b ? "true" : "false");
		} else if (o == "<") {
			cout << (a < b ? "true" : "false");
		} else if (o == "<=") {
			cout << (a <= b ? "true" : "false");
		} else if (o == "==") {
			cout << (a == b ? "true" : "false");
		} else if (o == "!=") {
			cout << (a != b ? "true" : "false");
		}
		cout << '\n';
		n++;
	}
}

// 주어진 관계식의 참/거짓 출력하기

// 연산자는 string으로 받아 연산자에 따라 다른 연산을 할 수 있도록 한다
// 그것만 빼면 단순 입력 문제...