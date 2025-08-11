// Mia
// https://www.acmicpc.net/problem/24765

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	while (true) {
		vector<int> input(4), res(2);
		for (int i = 0; i < 4; i++) {
			cin >> input[i];
		}
		if (input[0] == 0) {
			break;
		}
		for (int i = 0; i < 2; i++) {
			int a = min(input[i * 2], input[i * 2 + 1]);
			int b = max(input[i * 2], input[i * 2 + 1]);
			if (a == 1 && b == 2) {
				res[i] = 9999;
			} else if (a == b) {
				res[i] = a * 100;
			} else {
				res[i] = b * 10 + a;
			}
		}
		if (res[0] == res[1]) {
			cout << "Tie.";
		} else {
			cout << "Player " << (res[0] > res[1] ? "1" : "2") << " wins.";
		}
		cout << '\n';
	}
}

// 문제에서 주어진 대로 주사위 게임 결과 출력하기