// 미로 탐색
// https://www.acmicpc.net/problem/2178	

#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

class coord {
public:
	int x, y;
	coord(int x, int y) {
		this->x = x;
		this->y = y;
	}
	coord operator+(coord a) {
		coord p(this->x + a.x, this->y + a.y);
		return p;
	}
};

int main(void) {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> visit(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			if (s[j] == '0')
				visit[i][j] = -1;
			else
				visit[i][j] = 0;
		}
	}
	visit[0][0] = 1;
	coord d[4] = { coord(0, -1), coord(0, 1), coord(-1, 0), coord(1, 0) };
	int max = 1;
	queue<coord> q;
	q.push(coord(0, 0));
	while (!q.empty()) {
		coord c = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			coord cc = c + d[i];
			if (cc.x < 0 || cc.y < 0 || cc.x >= n || cc.y >= m)
				continue;
			if (visit[cc.x][cc.y] == 0) {
				visit[cc.x][cc.y] = visit[c.x][c.y] + 1;
				if (visit[cc.x][cc.y] > max)
					max = visit[cc.x][cc.y];
				q.push(cc);
			}
		}
	}
	cout << visit[n - 1][m - 1] << '\n';
}

// edge의 가중치가 없을 때, BFS로 찾은 경로는 언제나 최소 거리 경로임 -> 내 주변의 노드를 언제나 모두 탐색하니까