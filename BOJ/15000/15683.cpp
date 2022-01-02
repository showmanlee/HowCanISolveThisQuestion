// 감시
// https://www.acmicpc.net/problem/15683

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<pair<int, int>, int> prr;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int rotation[6][4][4] = {
	{{-1, -1, -1, -1}, {-1, -1, -1, -1}, {-1, -1, -1, -1}, {-1, -1, -1, -1}},
	{{0, -1, -1, -1}, {1, -1, -1, -1}, {2, -1, -1, -1}, {3, -1, -1, -1}},
	{{0, 2, -1, -1}, {1, 3, -1, -1}, {-1, -1, -1, -1}, {-1, -1, -1, -1}},
	{{0, 1, -1, -1}, {1, 2, -1, -1}, {2, 3, -1, -1}, {3, 0, -1, -1}},
	{{0, 1, 2, -1}, {1, 2, 3, -1}, {2, 3, 0, -1}, {3, 0, 1, -1}},
	{{0, 1, 2, 3}, {-1, -1, -1, -1}, {-1, -1, -1, -1}, {-1, -1, -1, -1}},
};

int n, m, s, res;
int board[9][9];
int decide[9];
prr cctv[9];

int calc() {
	vector<vector<bool>> visit(n, vector<bool>(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (board[i][j] != 0)
				visit[i][j] = true;
	for (int t = 0; t < s; t++) {
		int x = cctv[t].first.first;
		int y = cctv[t].first.second;
		int type = cctv[t].second;
		for (int i = 0; i < 4; i++) {
			int rot = rotation[type][decide[t]][i];
			if (rot == -1)
				break;
			int xx = x + dx[rot];
			int yy = y + dy[rot];
			while (xx >= 0 && yy >= 0 && xx < n && yy < m && board[xx][yy] != 6) {
				visit[xx][yy] = true;
				xx += dx[rot];
				yy += dy[rot];
			}
		}
	}
	int ret = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (!visit[i][j])
				ret++;
	return ret;
}

void dfs(int count) {
	if (count == s) {
		res = min(res, calc());
		return;
	}
	int n = 4;
	if (cctv[count].second == 2)
		n = 2;
	else if (cctv[count].second == 5)
		n = 1;
	for (int i = 0; i < n; i++) {
		decide[count] = i;
		dfs(count + 1);
	}
}

int main(void) {
	cin >> n >> m;
	s = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] >= 1 && board[i][j] <= 5)
				cctv[s++] = { {i, j}, board[i][j] };
		}
	}
	res = 987654321;
	dfs(0);
	cout << res << '\n';
}
// 벽이 있는 공간에 5가지 타입의 CCTV가 설치되었을 때, CCTV를 적절히 회전하여 최소화한 사각지대의 크기는?
// 1은 단방향, 2는 ㅡ형, 3는 ㄱ형, 4는 ㅗ형, 5는 전방향

// 브루트포스 - 브포에 필요한 정보인 CCTV 개수(최대 8개)와 각 CCTV의 좌표, 타입을 보드 입력 과정에서 저장
// 이후 재귀함수를 돌면서 각 CCTV의 회전 상태 결정 - 전역 배열 decide에 저장
// 여기서 2번 타입은 회전형이 2개, 5번 타입은 회전형이 하나 뿐이므로 이를 감안해 결정하기
// 결정이 끝나면 CCTV를 하나씩 작동하면서 사각지대 크기 확인 - 벽과 CCTV는 사각지대에 포함되지 않음에 주의
// 타입과 회전 방향 별로 CCTV가 뻗는 방향을 저장하는 3차원 배열을 만들어 시뮬레이션을 쉽게 만들기