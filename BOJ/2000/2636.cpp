// 치즈
// https://www.acmicpc.net/problem/2636

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int main(void) {
	int n, m, count = 0, day = 0;
	cin >> n >> m;
	vector<vector<bool>> cheese(n, vector<bool>(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			int p;
			cin >> p;
			cheese[i][j] = p;
			count += p;
		}
	while (true) {
		queue<int> qx, qy;
		qx.push(0);
		qy.push(0);
		vector<vector<bool>> melt(n, vector<bool>(m));
		vector<vector<bool>> visit(n, vector<bool>(m));
		while (!qx.empty()) {
			int x = qx.front();
			int y = qy.front();
			qx.pop();
			qy.pop();
			for (int i = 0; i < 4; i++) {
				int xx = x + dx[i];
				int yy = y + dy[i];
				if (xx < 0 || yy < 0 || xx >= n || yy >= m)
					continue;
				if (!visit[xx][yy]) {
					visit[xx][yy] = true;
					if (cheese[xx][yy])
						melt[xx][yy] = true;
					else {
						qx.push(xx);
						qy.push(yy);
					}
				}
			}
		}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (melt[i][j])
					cheese[i][j] = false;
		day++;
		int c = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (cheese[i][j])
					c++;
		if (c == 0)
			break;
		else
			count = c;
	}
	cout << day << '\n' << count << '\n';
}

// 치즈의 겉면이 공기에 닿아 한 시간 마다 녹을 때, 다 녹는 시간과 녹기 직전 남은 칸 수는?
// 가장자리는 공기임이 보장되기 때문에 겉면에 대해 BFS를 돌리면 된다
// BFS를 돌리면서 치즈와 만나면 녹는 부분 표시하고 큐가 비워지면 실제 치즈에서 녹이기