// 내 선물을 받아줘
// https://www.acmicpc.net/problem/15559

#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int group[1000001];

int finding(int p) {
	if (p == group[p])
		return p;
	return group[p] = finding(group[p]);
}

void unioning(int a, int b) {
	int ga = finding(a);
	int gb = finding(b);
	if (ga < gb)
		group[gb] = ga;
	else
		group[ga] = gb;
}

int dir(char c) {
	if (c == 'N')
		return 0;
	else if (c == 'E')
		return 1;
	else if (c == 'S')
		return 2;
	else
		return 3;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<vector<char>> board(n, vector<char>(m));
	vector<vector<int>> visit(n, vector<int>(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];
	int idx = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visit[i][j] == 0) {
				idx++;
				group[idx] = idx;
				visit[i][j] = idx;
				queue<pr> q;
				q.push({ i, j });
				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					q.pop();
					int xx = x + dx[dir(board[x][y])];
					int yy = y + dy[dir(board[x][y])];
					if (visit[xx][yy] == 0) {
						visit[xx][yy] = idx;
						q.push({ xx, yy });
					}
					else
						unioning(visit[xx][yy], idx);
				}
			}
		}
	}
	set<int> res;
	for (int i = 1; i <= idx; i++)
		res.insert(finding(i));
	cout << res.size() << '\n';
}

// 각 칸마다 이동할 수 있는 방향이 적힌 n*m 보드에 선물들을 놓을 때, 모든 칸에서 선물을 가져갈 수 있게 놔야 하는 최소 선물 개수는?

// 칸에 적힌 대로 이동했을 때 보드 바깥으로 벗어나지 않음이 보장됨 - 적힌대로 이동하면 어느 순간 반드시 순환선에 도달하게 됨
// 따라서 이 문제는 보드 안에 몇 개의 순환선이 있는지 알아내는 문제
// 순환선 속으로 들어가는 단방향 길도 순환선으로 보기 - union-find와 같은 원리로 접근
// 우선 보드를 받고, 각 칸마다 접근하지 않은 곳이 있다면 탐색 시작
// 새로운 사이클에 들어왔다면 idx를 하나 늘려 해당 사이클에 번호를 부여하고, union-find용 group 배열의 해당 인덱스도 초기화
// 이후 방문하지 않은 칸들을 방향따라 방문하며, 현재 idx를 visit의 해당 칸에 갱신
// 만약 방문한 칸을 밟았다면 해당 칸의 visit에 적힌 번호와 현재 idx를 union하여 하나의 그룹으로 만든 뒤 탐색 종료
// 마지막으로 1부터 idx까지의 그룹 번호를 모두 구한 후 중복을 제거한 개수를 구해 결과값으로 출력