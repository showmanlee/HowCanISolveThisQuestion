// 게리맨더링
// https://www.acmicpc.net/problem/17471

#include <iostream>
#include <string>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

int n;
int population[11];
vector<int> board[11];
int pick[11];
int res;

void verify() {
	bool same = true;
	for (int i = 1; i < n; i++)
		if (pick[i] != pick[i + 1])
			same = false;
	if (same)
		return;

	vector<int> block(n + 1, -1);
	vector<int> result;
	int count = 0;
	for (int i = 1; i <= n; i++) {
		if (block[i] == -1) {
			block[i] = count;
			int sum = 0;
			queue<int> q;
			q.push(i);
			while (!q.empty()) {
				int p = q.front();
				q.pop();
				sum += population[p];
				for (int j : board[p]) {
					if (pick[p] == pick[j] && block[j] == -1) {
						block[j] = count;
						q.push(j);
					}
				}
			}
			result.push_back(sum);
			count++;
		}
	}
	if (count > 2)
		return;
	res = min(res, abs(result[0] - result[1]));
}

void select(int i) {
	if (i > n) {
		verify();
		return;
	}
	pick[i] = 1;
	select(i + 1);
	pick[i] = 2;
	select(i + 1);
	pick[i] = 0;
}

int main(void) {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> population[i];
	for (int i = 1; i <= n; i++) {
		int p;
		cin >> p;
		for (int j = 0; j < p; j++) {
			int q;
			cin >> q;
			board[i].push_back(q);
		}
	}
	res = 987654321;
	select(1);
	if (res == 987654321)
		res = -1;
	cout << res << '\n';
}

// 각 지역을 두 선거구로 나누려는데, 만들 수 있는 두 선거구 차의 최소치는?
// 주어지는 구역 수가 최대 10개 - 브루트포스로 구역 산정 가능
// 브루트포스를 통해 구역들에 번호를 매긴 후, 모두 번호가 매겨지면 bfs 돌려보기
// 만약 bfs로 번호를 매긴 대로 선거구가 2개로 쪼개짐이 확인되면 해당 구역들의 인구 합들의 차를 구해 결과 갱신