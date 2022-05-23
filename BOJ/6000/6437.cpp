// Golf
// https://www.acmicpc.net/problem/6437

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int idx = 1;
	while (true) {
		int a, b;
		cin >> a >> b;
		if (a == 0 && b == 0) {
			break;
		}
		cout << "Hole #" << idx << '\n';
		if (b == 1) {
			cout << "Hole-in-one.\n";
		}
		else {
			switch (a - b) {
				case 3:
					cout << "Double eagle.\n";
					break;
				case 2:
					cout << "Eagle.\n";
					break;
				case 1:
					cout << "Birdie.\n";
					break;
				case 0:
					cout << "Par.\n";
					break;
				case -1:
					cout << "Bogey.\n";
					break;
				default:
					cout << "Double Bogey.\n";
					break;
			}
		}
		cout << '\n';
		idx++;
	}
}

// 각 홀의 PAR와 타수가 주어졌을 떄, 결과 출력하기

// +2타 이상일 경우 언제나 Double Bogey, 타수가 1이라면 언제나 Hole-in-one임에 주의
// 그것만 빼면 기본적인 반복문 문제