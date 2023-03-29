// 탁구 경기
// https://www.acmicpc.net/problem/27918

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	int d = 0, p = 0;
	for (int i = 0; i < n; i++) {
		char c;
		cin >> c;
		if (abs(d - p) < 2) {
			if (c == 'D') {
				d++;
			} else if (c == 'P') {
				p++;
			}
		}
	}
	cout << d << ':' << p << '\n';
}

// n라운드의 게임 결과가 주어지고, 게임 진행 중 점수차가 2점 이상 벌어지면 더 이상 점수를 카운트하지 않을 때, 최종 점수 구하기

// 2점 차가 발생하지 않는다면 계속 점수 카운팅하기