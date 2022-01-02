// 지뢰 찾기
// https://www.acmicpc.net/problem/4396

#include <iostream>
#include <vector>
using namespace std;
int dx[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int dy[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<vector<char>> mine(n, vector<char>(n));
	vector<vector<char>> opened(n, vector<char>(n));
	vector<vector<int>> res(n, vector<int>(n, -1));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> mine[i][j];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> opened[i][j];
	bool blown = false;
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			if (opened[x][y] == 'x') {
				if (mine[x][y] == '*') 
					blown = true;
				res[x][y] = 0;
				for (int i = 0; i < 8; i++) {
					int xx = x + dx[i];
					int yy = y + dy[i];
					if (xx < 0 || yy < 0 || xx >= n || yy >= n)
						continue;
					if (mine[xx][yy] == '*')
						res[x][y]++;
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (blown && mine[i][j] == '*')
				cout << '*';
			else
				cout << char(res[i][j] == -1 ? '.' : res[i][j] + '0');
		}
		cout << '\n';
	}
}

// 지뢰 찾기에서 지뢰 현황과 열린 칸들이 주어질 때, 열린 칸들에 적혀야 할 숫자 출력하기
// 만약 지뢰가 있는 칸이 열렸다면 지뢰가 있는 칸들을 *로 표시하기

// 각 칸을 순회하면서 열린 칸이라면 주변의 지뢰 현황 확인하기 - 만약 그 자리에 지뢰가 있으면 폭발 체크하기
// 이후 각 칸 주변에 있는 지뢰 수를 출력하는데, 만약 폭발했다면 지뢰가 있는 곳에 대신 * 표시하기