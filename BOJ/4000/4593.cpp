// Rock, Paper, Scissors
// https://www.acmicpc.net/problem/4593

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	while (true) {
		string a, b;
		cin >> a >> b;
		if (a == "E" && b == "E") {
			break;
		}
		int aa = 0, bb = 0;
		for (int i = 0; i < a.length(); i++) {
			if (a[i] != b[i]) {
				if (a[i] == 'R') {
					if (b[i] == 'S') {
						aa++;
					} else {
						bb++;
					}
				} else if (a[i] == 'S') {
					if (b[i] == 'P') {
						aa++;
					} else {
						bb++;
					}
				} else if (a[i] == 'P') {
					if (b[i] == 'R') {
						aa++;
					} else {
						bb++;
					}
				}
			}
		}
		cout << "P1: " << aa << '\n' << "P2: " << bb << '\n';
	}
}

// 연속 가위바위보 게임 결과가 주어졌을 때 각 플레이어의 득점 결과 출력하기

// 출력하면 됩니다 - 문자열 돌면서 점수 올려주기