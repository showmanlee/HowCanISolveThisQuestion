// 삼각형
// https://www.acmicpc.net/problem/29725

#include <iostream>
#include <cctype>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	int res = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			char c;
			cin >> c;
			switch (c) {
				case 'P':
					res += 1;
					break;
				case 'p':
					res -= 1;
					break;
				case 'N':
				case 'B':
					res += 3;
					break;
				case 'n':
				case 'b':
					res -= 3;
					break;
				case 'R':
					res += 5;
					break;
				case 'r':
					res -= 5;
					break;
				case 'Q':
					res += 9;
					break;
				case 'q':
					res -= 9;
					break;
				default:
					break;
			}
		}
	}
	cout << res << '\n';
}

// 체스판의 기물 점수는 백의 기물 점수 합에서 흑의 기물 점수 합을 뺀 값이고, 기물에 해당하는 킹, 폰, 나이트, 비숍, 룩, 퀸의 기물 점수는 각각 0, 1, 3, 3, 5, 9점일 때, 주어진 보드의 기물 점수 구하기

// 직접 구해주면 됩니다...