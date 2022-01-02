// Paint Bucket
// https://www.acmicpc.net/problem/15240

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<vector<char>> board(n, vector<char>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	int a, b;
	char c;
	cin >> a >> b >> c;
	queue<pr> q;
	q.push({ a, b });
	char key = board[a][b];
	board[a][b] = c;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (xx < 0 || yy < 0 || xx >= n || yy >= m) {
				continue;
			}
			if (board[xx][yy] == key) {
				board[xx][yy] = c;
				q.push({ xx, yy });
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << board[i][j];
		}
		cout << '\n';
	}
}

// n*m 그림판의 한 칸에 페인트통을 부었을 때 결과 출력하기

// 어떤 점에다 페인트를 부으면 그 칸과 연결된 모든 칸에 색이 칠해진다
// 그러니까 영역 탐색 bfs 문제라는 것
// 보드와 붓는 칸, 색을 받은 후 그 칸부터 시작해 원래 색으로 구성된 이어진 칸의 색을 모두 바꾼다