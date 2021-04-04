// 미세먼지 안녕!
// https://www.acmicpc.net/problem/17144

#include <iostream>
#include <vector>
using namespace std;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int main(void) {
	int r, c, t;
	cin >> r >> c >> t;
	vector<vector<int>> room(r + 1, vector<int>(c + 1));
	vector<vector<int>> dust(r + 1, vector<int>(c + 1));
	int airtop = 0, airbot = 0;
	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; j++) {
			cin >> room[i][j];
			if (room[i][j] == -1) {
				if (airtop == 0)
					airtop = i;
				else
					airbot = i;
			}
		}
	for (int tt = 0; tt < t; tt++) {
		for (int i = 1; i <= r; i++)
			for (int j = 1; j <= c; j++)
				dust[i][j] = 0;
		for (int i = 1; i <= r; i++)
			for (int j = 1; j <= c; j++) {
				int d = room[i][j] / 5;
				for (int k = 0; k < 4; k++) {
					int ii = i + dx[k];
					int jj = j + dy[k];
					if (ii < 1 || jj < 1 || ii > r || jj > c)
						continue;
					if (!(ii == airbot && jj == 1 || ii == airtop && jj == 1)) {
						dust[ii][jj] += d;
						dust[i][j] -= d;
					}
				}
			}
		for (int i = 1; i <= r; i++)
			for (int j = 1; j <= c; j++) {
				if (room[i][j] != -1) {
					room[i][j] += dust[i][j];
					if (room[i][j] < 0)
						room[i][j] = 0;
				}
			}

		for (int i = airtop - 1; i > 1; i--)
			room[i][1] = room[i - 1][1];
		for (int i = 1; i < c; i++)
			room[1][i] = room[1][i + 1];
		for (int i = 1; i < airtop; i++)
			room[i][c] = room[i + 1][c];
		for (int i = c; i > 1; i--)
			room[airtop][i] = room[airtop][i - 1];
		room[airtop][2] = 0;

		for (int i = airbot + 1; i < r; i++)
			room[i][1] = room[i + 1][1];
		for (int i = 1; i < c; i++)
			room[r][i] = room[r][i + 1];
		for (int i = r; i > airbot; i--)
			room[i][c] = room[i - 1][c];
		for (int i = c; i > 1; i--)
			room[airbot][i] = room[airbot][i - 1];
		room[airbot][2] = 0;
	}
	int res = 0;
	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; j++)
			if (room[i][j] != -1)
				res += room[i][j];
	cout << res << '\n';
}

// 미세먼지가 확산되고, 공기청정기는 돌아간다
// 미세먼지가 동시에 확산되므로 확산 계산용 배열을 따로 만들어야 함
// 공기 순환 구현에 유의