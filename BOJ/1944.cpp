// 복제 로봇
// https://www.acmicpc.net/problem/1944

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;
typedef pair<int, pr> prr;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int group[252];

int finding(int p) {
	if (p == group[p])
		return p;
	group[p] = finding(group[p]);
	return group[p];
}

void unioning(int a, int b) {
	int pa = finding(a);
	int pb = finding(b);
	if (pa > pb)
		group[pa] = pb;
	else if (pb > pa)
		group[pb] = pa;

}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> board(n, vector<int>(n));
	vector<pr> pos(m + 2);
	int no = 2;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			char c;
			cin >> c;
			if (c == '1')
				board[i][j] = -1;
			if (c == 'S')
				board[i][j] = 1;
			if (c == 'K')
				board[i][j] = no++;
			if (board[i][j] > 0)
				pos[board[i][j]] = { i, j };
		}
	}
	for (int i = 1; i <= m + 1; i++)
		group[i] = i;

	vector<prr> edges;
	for (int a = 1; a < m + 1; a++) {
		for (int b = a + 1; b <= m + 1; b++) {
			int sx = pos[a].first;
			int sy = pos[a].second;
			int gx = pos[b].first;
			int gy = pos[b].second;
			vector<vector<bool>> visit(n, vector<bool>(n));
			queue<prr> q;
			q.push({ 0, {sx, sy} });
			visit[sx][sy] = true;
			int len = -1;
			while (!q.empty()) {
				int x = q.front().second.first;
				int y = q.front().second.second;
				int d = q.front().first;
				q.pop();
				if (x == gx && y == gy) {
					len = d;
					break;
				}
				for (int i = 0; i < 4; i++) {
					int xx = x + dx[i];
					int yy = y + dy[i];
					if (xx < 0 || yy < 0 || xx >= n || yy >= n || visit[xx][yy])
						continue;
					if (board[xx][yy] != -1) {
						visit[xx][yy] = true;
						q.push({ d + 1, {xx, yy} });
					}
				}
			}
			if (len != -1)
				edges.push_back({ len, {a, b} });
		}
	}
	sort(edges.begin(), edges.end());
	int cnt = 0, res = 0;
	for (prr& e : edges) {
		int c = e.first;
		int a = e.second.first;
		int b = e.second.second;
		if (finding(a) != finding(b)) {
			unioning(a, b);
			cnt++;
			res += c;
		}
		if (cnt == m)
			break;
	}
	if (cnt != m)
		res = -1;
	cout << res << '\n';
}

// m개의 열쇠가 있는 n*n 보드에서 출발지와 열쇠 위치에서 스스로를 무한정 복제할 수 있는 로봇을 놓을 때, 모든 로봇의 최소 이동 횟수의 합은?

// 로봇이 복제한다 = 진행 방향이 여러 갈래로 나뉜다 = 출발점에서 서로 다른 열쇠 위치로 가는 경로들은 독립적이다
// 열쇠 위치에서도 로봇이 복제한다 = 열쇠 위치도 다른 열쇠를 집기 위한 출발지가 될 수 있다 = 해당 위치에서 출발하는 경로들 역시 독립적이다
// 따라서 이 문제는 이러한 '독립적인 경로'들로 구성된 MST의 길이를 찾는 문제라 볼 수 있음 - 출발점과 열쇠가 노드, 이들을 잇는 bfs가 간선의 길이

// 입력 단에서는 열쇠에 별도의 코드가 부여되지 않으므로 여기서 부여해야 함 - char로 입력되는 보드를 int 형태로 저장
// -1은 벽, 0은 땅, 1은 출발점, 2~는 열쇠 - MST의 '노드'에 1 ~ m + 1의 번호를 부여하고, 해당 노드의 위치를 따로 배열에 저장하기
// 이후 각 노드간의 최단거리를 bfs로 구하고, 해당 최단 거리를 간선화하여 저장한다 - 보드의 크기가 최대 50이고, 노드의 개수가 최대 251개이므로 충분히 탐색 가능
// bfs로 최단거리를 찾을 수 없다면 간선 만들지 않기
// 마지막으로 간선들을 정렬하고, 크루스칼을 돌려 MST 만들기 - 만약 간선 개수가 m개가 아니라면 탈락