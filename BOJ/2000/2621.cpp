// 카드게임
// https://www.acmicpc.net/problem/2621

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<int> color(4), number(10);
	int five = 0, four = 0, three = 0, two1 = 0, two2 = 0, maxx = 0;
	bool straight = false, flush = false;
	for (int i = 0; i < 5; i++) {
		char a, b;
		cin >> a >> b;
		if (a == 'R') {
			color[0]++;
		} else if (a == 'G') {
			color[1]++;
		} else if (a == 'B') {
			color[2]++;
		} else {
			color[3]++;
		}
		number[b - '0']++;
		maxx = max(maxx, b - '0');
	}
	for (int i = 1; i <= 9; i++) {
		if (number[i] == 5) {
			five = i;
		} else if (number[i] == 4) {
			four = i;
		} else if (number[i] == 3) {
			three = i;
		} else if (number[i] == 2) {
			if (two1 != 0) {
				two2 = i;
			} else {
				two1 = i;
			}
		}
	}
	for (int i = 0; i < 4; i++) {
		if (color[i] == 5) {
			flush = true;
		}
	}
	for (int i = 1; i <= 6; i++) {
		if (number[i] == 1 && number[i + 1] == 1 && number[i + 2] == 1 && number[i + 3] == 1 && number[i + 4] == 1) {
			straight = true;
		}
	}
	int res = 0;
	if (flush && straight) {
		res = 900 + maxx;
	} else if (four != 0) {
		res = 800 + four;
	} else if (three != 0 && two1 != 0) {
		res = 700 + three * 10 + two1;
	} else if (flush) {
		res = 600 + maxx;
	} else if (straight) {
		res = 500 + maxx;
	} else if (three != 0) {
		res = 400 + three;
	} else if (two1 != 0 && two2 != 0) {
		res = 300 + max(two1, two2) * 10 + min(two1, two2);
	} else if (two1 != 0) {
		res = 200 + two1;
	} else {
		res = 100 + maxx;
	}
	cout << res << '\n';
}

// 4가지 색의 1~9 숫자가 적힌 카드 5장의 조합으로 얻을 수 있는 최고 점수 구하기(점수 계산법은 문제 참고)

// 따져야 하는 부분은 같은 색깔 개수, 같은 숫자 개수, 연속성, 동일 숫자 개수
// 동일 숫자의 경우 5, 4, 3은 경우가 하나, 2는 경우가 2개임 - 이를 주의하며 해당 경우의 수와 그때 등장하는 수 구해두기
// 점수 계산 특성 상 무조건 높은 단계가 높은 점수를 받는다