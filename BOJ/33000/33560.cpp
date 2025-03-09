// 수상한 어릿광대
// https://www.acmicpc.net/problem/33560

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int res[5] = {0, 0, 0, 0, 0};

void gameOver(int score) {
	if (score >= 35 && score < 65) {
		res[1]++;
	} else if (score >= 65 && score < 95) {
		res[2]++;
	} else if (score >= 95 && score < 125) {
		res[3]++;
	} else if (score >= 125) {
		res[4]++;
	}
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> comm(n);
	for (int i = 0; i < n; i++) {
		cin >> comm[i];
	}
	int score = 0;
	int add = 1;
	int time = 0;
	int amount = 4;
	for (int p : comm) {
		if (p == 1) {
			gameOver(score);
			add = 1;
			amount = 4;
			time = -amount;
			score = -add;
		} else if (p == 2) {
			if (add > 1) {
				add /= 2;
			} else {
				amount += 2;
			}
		} else if (p == 3) {
			// none
		} else if (p == 4) {
			time += 56;
		} else if (p == 5) {
			if (amount > 1) {
				amount--;
			}
		} else if (p == 6) {
			if (add < 32) {
				add *= 2;
			}
		}
		score += add;
		time += amount;
		if (time > 240) {
			gameOver(score);
			add = 1;
			amount = 4;
			time = 0;
			score = 0;
		}
	}

	for (int i = 1; i <= 4; i++) {
		cout << res[i] << '\n';
	}
}

// 주어진 방식대로 게임을 한 결과 출력하기