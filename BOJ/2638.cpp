// 치즈
// https://www.acmicpc.net/problem/2638

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int main(void) {
	int n, m, day = 0, count = 0;
	cin >> n >> m;
	vector<vector<bool>> cheese(n, vector<bool>(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			int p;
			cin >> p;
			cheese[i][j] = p;
			if (cheese[i][j])
				count++;
		}
	while (true) {
		queue<int> qx, qy;
		qx.push(0);
		qy.push(0);
		vector<vector<int>> melt(n, vector<int>(m));
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
					if (cheese[xx][yy])
						melt[xx][yy]++;
					else {
						visit[xx][yy] = true;
						qx.push(xx);
						qy.push(yy);
					}
				}
			}
		}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (melt[i][j] >= 2) {
					cheese[i][j] = false;
					count--;
				}
		day++;
		if (count <= 0)
			break;
	}
	cout << day << '\n';
}

// 2636 치즈의 업그레이드 버전 - 이번엔 두 면 이상이 닿아야 녹는다! 그리고 녹기 직전 개수도 안 구해도 됨
// 원리는 그대로, 녹는 배열은 bool에서 int로 바꾸기