// 가위 바위 보?
// https://www.acmicpc.net/problem/4493

#include <iostream>
using namespace std;

int main(void) {
	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		int n;
		cin >> n;
		int p1 = 0, p2 = 0;
		for (int i = 0; i < n; i++) {
			char c1, c2;
			cin >> c1 >> c2;
			if (c1 == c2) {
				p1++;
				p2++;
			}
			else if (c1 == 'R') {
				if (c2 == 'S')
					p1++;
				else if (c2 == 'P')
					p2++;
			}
			else if (c1 == 'S') {
				if (c2 == 'P')
					p1++;
				else if (c2 == 'R')
					p2++;
			}
			else if (c1 == 'P') {
				if (c2 == 'R')
					p1++;
				else if (c2 == 'S')
					p2++;
			}
		}
		if (p1 == p2)
			cout << "TIE\n";
		else
			cout << "Player " << (p1 > p2 ? "1" : "2") << '\n';
	}
}

// 가위바위보 n게임을 했을 때 최종 결과 판정하기
// 조건문 조건문 조건문