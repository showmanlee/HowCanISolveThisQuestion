// Card Cutting
// https://www.acmicpc.net/problem/5087

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	char c;
	int a = 0, b = 0;
	while (true) {
		cin >> c;
		if (c == '#') {
			break;
		} else if (c == '*') {
			cout << (a == b ? "Draw" : (a > b ? "Cheryl" : "Tania")) << '\n';
			a = b = 0;
			continue;
		}
		int p = c - '0';
		if (c == '1') {
			cin >> c;
			p = 10;
		} else if (c == 'A') {
			p = 1;
		}
		if (p % 2 == 1) {
			a++;
		} else {
			b++;
		}
	}
}

// 1~10까지 뽑는 카드게임에서 홀수만 모은 사람과 짝수만 모은 사람의 숫자 합 보고 승자 구하기