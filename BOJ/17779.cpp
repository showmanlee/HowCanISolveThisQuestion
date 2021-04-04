// 게리맨더링 2
// https://www.acmicpc.net/problem/17779

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int n;
int board[21][21];
int res;

void divide(int x, int y, int d1, int d2) {
	vector<vector<int>> zone(n + 1, vector<int>(n + 1));
	vector<int> count(6);

	for (int i = 0; i <= d1; i++) {
		zone[x + i][y - i] = 5;
		zone[x + d2 + i][y + d2 - i] = 5;
	}
	for (int i = 0; i <= d2; i++) {
		zone[x + i][y + i] = 5;
		zone[x + d1 + i][y - d1 + i] = 5;
	}

	queue<pr> q;
	q.push({ x + 1, y });
	zone[x + 1][y] = 5;
	for (int i = 2; i <= n - 1; i++) {
		for (int j = 2; j <= n - 1; j++) {
			if (zone[i - 1][j] == 5 && zone[i + 1][j] == 5 && zone[i][j + 1] == 5 && zone[i][j - 1] == 5 && zone[i][j] == 0) {
				q.push({ i, j });
				zone[i][j] = 5;
			}
		}
	}
	while (!q.empty()) {
		int tx = q.front().first;
		int ty = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int xx = tx + dx[i];
			int yy = ty + dy[i];
			if (xx <= 0 || yy <= 0 || xx > n || yy > n)
				continue;
			if (zone[xx][yy] == 0) {
				zone[xx][yy] = 5;
				q.push({ xx, yy });
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (zone[i][j] == 0) {
				if (i >= 1 && i < x + d1 && j >= 1 && j <= y)
					zone[i][j] = 1;
				else if (i >= 1 && i <= x + d2 && j > y && j <= n)
					zone[i][j] = 2;
				else if (i >= x + d1 && i <= n && j >= 1 && j < y - d1 + d2)
					zone[i][j] = 3;
				else if (i > x + d2 && i <= n && j >= y - d1 + d2 && j <= n)
					zone[i][j] = 4;
			}
		}
	}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			count[zone[i][j]] += board[i][j];
	sort(count.begin() + 1, count.end());
	res = min(count[5] - count[1], res);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> board[i][j];

	res = 987654321;
	for (int x = 1; x <= n; x++) {
		for (int y = 1; y <= n; y++) {
			for (int d1 = 1; d1 <= n; d1++) {
				for (int d2 = 1; d2 <= n; d2++) {
					if (x < x + d1 + d2 && x + d1 + d2 <= n &&
						y - d1 >= 1 && y - d1 < y && y < y + d2 && y + d2 <= n)
						divide(x, y, d1, d2);
				}
			}
		}
	}

	cout << res << '\n';
}

// 각 칸마다 인구가 다른 n*n 도시에서 아래와 같은 방식으로 선거구를 5개로 나눈 경우 선거구 인구의 최대/최소의 차를 최소로 하는 경우의 차는?
//	기준점(x, y)와 경계의 길이 d1, d2를 정한다. (d1, d2 >= 1, 1 <= x < x + d1 + d2 <= N, 1 <= y - d1 < y < y + d2 <= N)			...(1)
//	다음 칸은 경계선이다.																							    		...(2)
//		(x, y), (x + 1, y - 1), ..., (x + d1, y - d1)
//		(x, y), (x + 1, y + 1), ..., (x + d2, y + d2)
//		(x + d1, y - d1), (x + d1 + 1, y - d1 + 1), ... (x + d1 + d2, y - d1 + d2)
//		(x + d2, y + d2), (x + d2 + 1, y + d2 - 1), ..., (x + d2 + d1, y + d2 - d1)
//	경계선과 경계선의 안에 포함되어있는 곳은 5번 선거구이다.
//	5번 선거구에 포함되지 않은 구역(r, c)의 선거구 번호는 다음 기준을 따른다.													...(3)
//		1번 선거구 : 1 <= r < x + d1, 1 <= c <= y
//		2번 선거구 : 1 <= r <= x + d2, y < c <= N
//		3번 선거구 : x + d1 <= r <= N, 1 <= c < y - d1 + d2
//		4번 선거구 : x + d2 < r <= N, y - d1 + d2 <= c <= N

// 경계 형성 법칙을 비주얼적으로 이해하면...
// - 마름모의 위쪽 꼭짓점을 기준으로 잡고, 올라가는 대각선의 길이와 내려가는 대각선의 길이를 정해 마름모를 그어준다
// - 그 마름모의 경계와 내부를 5번 선거구로 채운다.
// - 이후 마름모 꼭짓점들에서부터 보드 경계와 수직이 되도록 선분을 그어준다.
// - 좌상단(위쪽 꼭짓점 경계 포함)은 1번, 우상단(오른쪽 꼭짓점 경계 포함)은 2번, 좌하단(왼쪽 꼭짓점 경계 포함)은 3번, 우하단(아래쪽 꼭짓점 경계 포함)은 4번 선거구로 채운다.

// 1과 마찬가지로 브루트포스로 접근하는 문제(최대 20^4이나 실제로는 그보다 휠씬 적음) - 다만 여기서는 마름모 모양 구획을 나눠서 계산해야 한다
// 구획을 나누고, 경계를 그어준 후, 마름모 안쪽은 5번, 바깥쪽은 각자의 수로 채운다
// 이를 위해 (1)의 조건식을 활용해 x, y, d1, d2 범위를 판정해 4중 for를 돌리며 구획 확정하기
// 이후 구획을 결정하는 배열을 만들고, (2)에 맞게 5번 경계를 그어준 후, 반드시 5번 선거구에 들어가는 (x + 1, y)와 사면이 5로 둘러싸인 곳들(bfs 고립 방지)부터 시작해 bfs를 돌리며 이를 채워준다.
// 마지막으로 (3)에 맞게 나머지 구획을 넣어준 후 각 구역의 인구수를 모두 더해주고, 최대치와 최소치의 차를 얻어 결과 갱신하기

// 정 조건 짜맞추기 힘들면 문제에 나온 조건식 그대로 대입하면 ok