// 나이트의 이동
// https://www.acmicpc.net/problem/7562

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(void) {
	int dx[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
	int dy[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		vector<vector<int>> visit(n, vector<int>(n));
		int x, y, fx, fy;
		cin >> x >> y >> fx >> fy;
		queue<int> qx, qy;
		qx.push(x);
		qy.push(y);
		while (!qx.empty()) {
			int tx = qx.front();
			int ty = qy.front();
			if (tx == fx && ty == fy)
				break;
			qx.pop();
			qy.pop();
			for (int i = 0; i < 8; i++) {
				int xx = tx + dx[i];
				int yy = ty + dy[i];
				if (xx < 0 || yy < 0 || xx >= n || yy >= n)
					continue;
				if (visit[xx][yy] == 0) {
					visit[xx][yy] = visit[tx][ty] + 1;
					qx.push(xx);
					qy.push(yy);
				}
			}
		}
		cout << visit[fx][fy] << '\n';
	}
}

// 가중치가 없는 그래프에서 BFS로 찾은 경로는 반드시 최단 경로를 보장한다
// 나아가는 모양만 다를 뿐 비슷한 BFS 문제