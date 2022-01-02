// ⚾
// https://www.acmicpc.net/problem/17281

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n;
int score[51][10];
int order[10];
bool picked[10];
int res;

void calculate() {
	int result = 0, player = 1;
	for (int inning = 1; inning <= n; inning++) {
		queue<int> ground;
		for (int i = 0; i < 3; i++)
			ground.push(0);
		int out = 0;
		while (true) {
			if (score[inning][order[player]] == 0) 
				out++;
			else {
				for (int i = 0; i < score[inning][order[player]]; i++) {
					ground.push((i == 0 ? 1 : 0));
					result += ground.front();
					ground.pop();
				}
			}
			player++;
			if (player > 9)
				player = 1;
			if (out == 3)
				break;
		}
	}
	res = max(result, res);
}

void select(int k) {
	if (k == 10) {
		calculate();
		return;
	}
	for (int i = 1; i <= 9; i++) {
		if (!picked[i]) {
			picked[i] = true;
			order[i] = k;
			select(k + 1);
			picked[i] = false;
		}
	}
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 9; j++)
			cin >> score[i][j];
	}

	res = 0;
	order[4] = 1;
	picked[4] = true;
	select(2);
	cout << res << '\n';
}

// 매 이닝 당 선수 9명이 치는 루타 수가 주어진다. 1번 선수를 4번 타자로 하고, 나머지 선수들의 타순을 결정할 때, 얻을 수 있는 최대 점수는?
// 타순을 결정하는데 브포 사용 - 1번은 무조건 4번 타자, 나머지는 맘대로 - 각 타순에 몇 번 선수가 들어오는지 저장하는 배열 활용
// 야구 규칙 - 3아웃 발생 시 공수교대, 하지만 타순을 초기화하지는 않음
// 따라서 이닝 순회와 별도로 타순을 관리해주어야 함
// 그라운드 구현에는 큐를 활용 - 타자가 있는 경우 1, 없는 경우 0 저장
// 처음에는 0 3개를 저장해뒀다가 1~4루타 시 처음에는 1, 나머지는 0을 삽입 - 그와 동시에 가장 앞에 있는 수를 빼면서 그 수를 점수에 누적

// 기본적인 야구 규칙에 대한 이해가 필요함에 주의