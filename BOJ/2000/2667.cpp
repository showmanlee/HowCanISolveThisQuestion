// 단지번호붙이기
// https://www.acmicpc.net/problem/2667

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int dfs(vector<vector<bool>>& village, vector<vector<bool>>& visit, int x, int y, int n) {
	visit[x][y] = true;
	int ret = 1;
	for (int i = 0; i < 4; i++) {
		int xx = x + dx[i];
		int yy = y + dy[i];
		if (xx < 0 || yy < 0 || xx >= n || yy >= n)
			continue;
		if (village[xx][yy] && !visit[xx][yy])
			ret += dfs(village, visit, xx, yy, n);
	}
	return ret;
}

int main(void) {
	int n;
	cin >> n;
	vector<vector<bool>> village(n, vector<bool>(n));
	vector<vector<bool>> visit(n, vector<bool>(n));
	vector<int> group;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j++)
			village[i][j] = s[j] == '1';
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int k = 0;
			if (!visit[i][j] && village[i][j])
				k = dfs(village, visit, i, j, n);
			if (k != 0)
				group.push_back(k);
		}
	}

	sort(group.begin(), group.end());
	cout << group.size() << '\n';
	for (int i = 0; i < group.size(); i++) {
		cout << group[i] << '\n';
	}
}