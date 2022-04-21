// 직각 삼각형의 두 변
// https://www.acmicpc.net/problem/6322

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cout << fixed;
	cout.precision(3);
	int cnt = 1;
	while (true) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == b && b == c && c == 0) {
			break;
		}
		cout << "Triangle #" << cnt << '\n';
		if (a == -1) {
			double res = pow(c, 2) - pow(b, 2);
			if (res <= 0) {
				cout << "Impossible.\n\n";
			}
			else {
				cout << "a = " << sqrt(res) << "\n\n";
			}
		}
		else if (b == -1) {
			double res = pow(c, 2) - pow(a, 2);
			if (res <= 0) {
				cout << "Impossible.\n\n";
			}
			else {
				cout << "b = " << sqrt(res) << "\n\n";
			}
		}
		else if (c == -1) {
			double res = pow(a, 2) + pow(b, 2);
			if (res <= 0) {
				cout << "Impossible.\n\n";
			}
			else {
				cout << "c = " << sqrt(res) << "\n\n";
			}
		}
		cnt++;
	}
}

// 직각삼각형의 변 a, b, c 중 2개가 주어졌을 때, 나머지 한 변의 길이 구하기

// 피타고라스의 정리에 각 변수를 대입하여 푼다
// 여기서 빈칸의 수가 0 이하가 나오는 경우 impossible 판정