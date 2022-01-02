// 다리 만들기
// https://www.acmicpc.net/problem/17472

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;
typedef pair<int, pr> prr;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int group[7];

int finding(int p) {
	if (group[p] == p)
		return p;
	return group[p] = finding(group[p]);
}

void unioning(int a, int b) {
	int ga = finding(a);
	int gb = finding(b);
	if (ga > gb)
		group[ga] = gb;
	else if (ga < gb)
		group[gb] = ga;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> board(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			board[i][j] *= -1;
		}
	}
	int islands = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == -1) {
				islands++;
				board[i][j] = islands;
				queue<pr> q;
				q.push({ i, j });
				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					q.pop();
					for (int t = 0; t < 4; t++) {
						int xx = x + dx[t];
						int yy = y + dy[t];
						if (xx < 0 || yy < 0 || xx >= n || yy >= m)
							continue;
						if (board[xx][yy] == -1) {
							board[xx][yy] = islands;
							q.push({ xx, yy });
						}
					}
				}
			}
		}
	}
	for (int i = 1; i <= islands; i++)
		group[i] = i;
	vector<prr> edges;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] != 0) {
				for (int t = 0; t < 4; t++) {
					int len = -1;
					int beg = board[i][j];
					int dest = -1;
					int xx = i;
					int yy = j;
					while (true) {
						xx += dx[t];
						yy += dy[t];
						len++;
						if (xx < 0 || yy < 0 || xx >= n || yy >= m)
							break;
						if (board[xx][yy] == beg)
							break;
						else if (board[xx][yy] != 0) {
							if (len >= 2)
								dest = board[xx][yy];
							break;
						}
					}
					if (dest != -1)
						edges.push_back({ len, {beg, dest} });
				}
			}
		}
	}
	sort(edges.begin(), edges.end());
	int cnt = 0, res = 0;
	for (prr& e : edges) {
		int l = e.first;
		int a = e.second.first;
		int b = e.second.second;
		if (finding(a) != finding(b)) {
			unioning(a, b);
			cnt++;
			res += l;
		}
		if (cnt == islands - 1)
			break;
	}
	if (cnt != islands - 1)
		res = -1;
	cout << res << '\n';
}

// 여러 개의 섬으로 이루어진 n*m 보드에서 서로 다른 섬끼리 일직선으로 길이 2 이상의 다리를 놓아 모든 섬을 연결할 수 있는 다리 길이의 합의 최솟값은?

// 우선 섬들에 번호를 매긴다 - 섬의 개수는 최대 6개임이 보장됨
// 최초로 보드를 입력받을 때 1을 -1로 바꾼 후, 다시 전체 보드 칸을 순회하면서 -1인 칸을 발견했다면 해당 칸에 고유 섬 번호를 넣는다
// 그리고 bfs로 해당 지점과 이어진 모든 칸에 해당 번호를 덮어씌운다
// 이후 가능한 다리의 수를 구하기 위해 다시 칸을 순회하고, 만약 해당 칸이 섬의 일부라면 그 칸부터 상하좌우로 다리를 뻗어본다
// 만약 다리가 맵을 벗어나거나, 길이가 1 이하거나, 같은 섬으로 돌아온다면 패스, 그렇지 않다면 다리의 길이와 시작/종료 지점을 저장
// 이 이후부터는 섬을 노드로 하는 mst 구하기 - 섬을 노드로 한 크루스칼을 돌리며 섬-1개의 다리를 놓으면 완성, 그렇지 않으면 실패 판정
// 결과적으로 bfs + mst 문제