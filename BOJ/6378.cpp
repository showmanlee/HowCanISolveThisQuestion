// 디지털 루트
// https://www.acmicpc.net/problem/6378

#include <iostream>
#include <string>
using namespace std;

int main(void) {
	while (true) {
		string s;
		cin >> s;
		if (s == "0")
			break;
		int p = 0;
		while (true) {
			for (char c : s)
				p += c - '0';
			if (p / 10 == 0) {
				cout << p << '\n';
				break;
			}
			s = to_string(p);
			p = 0;
		}
	}
}

// 어떤 정수의 모든 자릿수를 더하는 것을 반복하여 한 자리 수로 만들기
// 기본적으로 1000자리가 주어질 수 있기 때문에 초기 input은 string으로, 이후 자릿수 합산 과정은 int로 처리
// 한자릿수가 될 때까지 반복하기 - 합산 과정을 string으로 옮겨주면서