// 캐슬 디펜스
// https://www.acmicpc.net/problem/17135

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<pair<int, int>, int> prr;
int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { -1, 0, 1, 0 };

int n, m, d;
int board[15][15];
int res;

void simulate(int first, int second, int third) {
	vector<vector<int>> sim(n, vector<int>(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			sim[i][j] = board[i][j];
	prr archer[3] = { {{n, first}, 1}, {{n, second}, 1} , {{n, third}, 1} };
	int ret = 0;
	for (int p = 0; p < n; p++) {
		for (int t = 0; t < 3; t++) {
			vector<vector<bool>> visit(n, vector<bool>(m));
			queue<prr> q;
			q.push(archer[t]);
			while (!q.empty()) {
				bool flag = false;
				int x = q.front().first.first;
				int y = q.front().first.second;
				int dist = q.front().second;
				q.pop();
				for (int i = 0; i < 4; i++) {
					int xx = x + dx[i];
					int yy = y + dy[i];
					if (xx < 0 || yy < 0 || xx >= n || yy >= m)
						continue;
					if (!visit[xx][yy]) {
						visit[xx][yy] = true;
						if (sim[xx][yy] >= 1) {
							flag = true;
							sim[xx][yy] = 2;
						}
						else {
							if (dist + 1 <= d)
								q.push({ {xx, yy}, dist + 1 });
						}
					}
					if (flag)
						break;
				}
				if (flag)
					break;
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (sim[i][j] == 2) {
					sim[i][j] = 0;
					ret++;
				}
			}
		}
		for (int i = n - 1; i >= 1; i--) {
			for (int j = 0; j < m; j++) {
				sim[i][j] = sim[i - 1][j];
			}
		}
		for (int j = 0; j < m; j++)
			sim[0][j] = 0;
	}
	res = max(ret, res);
}

void select(int first, int second, int third) {
	if (first != -1 && second != -1 && third != -1)
		simulate(first, second, third);
	else if (first != -1 && second != -1) {
		for (int i = second + 1; i < m; i++)
			select(first, second, i);
	}
	else if (first != -1) {
		for (int i = first + 1; i < m; i++)
			select(first, i, -1);
	}
	else {
		for (int i = 0; i < m; i++)
			select(i, -1, -1);
	}
}

int main(void) {
	cin >> n >> m >> d;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];
	res = 0;
	select(-1, -1, -1);
	cout << res << '\n';
}

// 점점 아래로 내려오는 적들을 사거리가 D인 궁수 3명이 공격할 때, 막을 수 있는 적의 최대 수는?
// 궁수는 맨 아랫줄 한칸 아래에 있고, 사거리는 맨해튼 거리로 따진다 - 배치할 수 있는 경우의 수는 mC3 - 브포!
// 브루트포스로 궁수 위치를 잡고, 궁수의 위치에서 거리가 정해진 bfs를 수행하며 한 칸씩 타격(왼쪽이 우선)
// 조건이 같을 경우 적이 화살을 동시에 맞을 수도 있음에 주의 - 제거 판정은 공격 판정이 끝난 후에 실행
// 타격당한 적은 별도의 표식을 붙이되, 다른 궁수도 타격당한 적을 맞출 수 있도록 처리
// 이후 보드를 점검하면서 타격된 적을 제거한 뒤, 한 칸씩 아래로 내리기(0행은 0번으로 채우기)