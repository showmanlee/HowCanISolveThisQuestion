// 적록색약
// https://www.acmicpc.net/problem/10026

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

void dfs(vector<vector<char>>& illust, vector<vector<bool>>& visit, int x, int y, int n) {
	visit[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int xx = x + dx[i];
		int yy = y + dy[i];
		if (xx < 0 || yy < 0 || xx >= n || yy >= n)
			continue;
		if (!visit[xx][yy] && illust[xx][yy] == illust[x][y])
			dfs(illust, visit, xx, yy, n);
	}
}

int main(void) {
	int n;
	cin >> n;
	vector<vector<char>> illust_normal(n, vector<char>(n));
	vector<vector<char>> illust_blind(n, vector<char>(n));
	vector<vector<bool>> visit_normal(n, vector<bool>(n));
	vector<vector<bool>> visit_blind(n, vector<bool>(n));
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j++) {
			if (s[j] == 'G') {
				illust_normal[i][j] = 'G';
				illust_blind[i][j] = 'R';
			}
			else
				illust_normal[i][j] = illust_blind[i][j] = s[j];
		}
	}

	int a = 0, b = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (!visit_normal[i][j]) {
				a++;
				dfs(illust_normal, visit_normal, i, j, n);
			}
			if (!visit_blind[i][j]) {
				b++;
				dfs(illust_blind, visit_blind, i, j, n);
			}
		}

	cout << a << ' ' << b << '\n';
}

// 적록색약자는 R과 G를 한 영역으로 판단