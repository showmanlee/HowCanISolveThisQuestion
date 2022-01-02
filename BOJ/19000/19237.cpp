// 어른 상어
// https://www.acmicpc.net/problem/19237

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;
typedef pair<pr, int> prr;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<int>> board(n, vector<int>(n));
	vector<int> status(m + 1);
	vector<vector<vector<int>>> dir(m + 1, vector<vector<int>>(4, vector<int>(4)));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> board[i][j];
	for (int i = 1; i <= m; i++) {
		cin >> status[i];
		status[i]--;
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j < 4; j++) {
			for (int l = 0; l < 4; l++) {
				cin >> dir[i][j][l];
				dir[i][j][l]--;
			}
		}
	}
	vector<vector<pr>> smell(n, vector<pr>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (board[i][j] != 0)
				smell[i][j] = { board[i][j], k + 1 };
	int remain = m;
	int res = 0;
	while (remain > 1) {
		res++;
		if (res > 1000) {
			res = -1;
			break;
		}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				smell[i][j].second = max(0, smell[i][j].second - 1);

		vector<prr> next(m + 1);
		for (int t = 1; t <= m; t++) {
			if (status[t] == -1)
				continue;
			int x = 0, y = 0;
			int d = status[t];
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (board[i][j] == t) {
						x = i;
						y = j;
					}
				}
			}
			bool moved = false;
			for (int i = 0; i < 4; i++) {
				int xx = x + dx[dir[t][d][i]];
				int yy = y + dy[dir[t][d][i]];
				if (xx < 0 || yy < 0 || xx >= n || yy >= n)
					continue;
				if (smell[xx][yy].second == 0) {
					moved = true;
					next[t] = { {xx, yy}, dir[t][d][i] };
					break;
				}
			}
			if (moved)
				continue;
			for (int i = 0; i < 4; i++) {
				int xx = x + dx[dir[t][d][i]];
				int yy = y + dy[dir[t][d][i]];
				if (xx < 0 || yy < 0 || xx >= n || yy >= n)
					continue;
				if (smell[xx][yy].first == t) {
					next[t] = { {xx, yy}, dir[t][d][i] };
					break;
				}
			}
		}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				board[i][j] = 0;
		for (int i = 1; i <= m; i++) {
			if (status[i] == -1)
				continue;
			if (board[next[i].first.first][next[i].first.second] == 0) {
				board[next[i].first.first][next[i].first.second] = i;
				smell[next[i].first.first][next[i].first.second] = {i, k + 1};
				status[i] = next[i].second;
			}
			else {
				status[i] = -1;
				remain--;
			}
		}
	}
	cout << res << '\n';
}

// n*n 보드 안의 번호가 붙은 m마리의 상어가 다음과 같은 과정으로 움직일 때, 1번 상어만 남게 되는 시점은(1000초가 넘어가면 -1)?
// - 모든 상어는 초당 한 칸씩 움직이며, 움직이면 그 뒤에 k초 동안 남는 냄새가 남는다
// - 상어는 상하좌우로 인접한 칸으로 움직일 수 있는데, 냄새가 없는 칸을 우선으로 하고, 냄새가 없는 칸이 없으면 자신의 냄새가 남은 곳으로 이동한다
// - 만약 조건에 만족하는 칸이 여러 개라면, 현재 상어가 보는 방향에 따른 방향 우선순위에 따라 이동할 칸을 결정한다
// - 이동 후 상어가 보는 방향은 이동한 방향이 된다
// - 모든 상어는 동시에 움직이며, 만약 같은 위치에 두 마리 이상의 상어가 모일 경우 가장 번호가 낮은 한 마리를 제외한 모든 상어가 사라진다

// 요구 사항이 제법 많은 구현 문제
// 우선 입력으로 현재 상어들의 위치를 담은 보드, 상어들이 보고 있는 방향, 상어들의 방향별 탐색 우선순위를 저장
// 회전 관련 값들은 -1하여 0~3에서 작동할 수 있게 함
// 냄새 정보를 저장하는 2차원 배열은 각 칸에 냄새 주인과 냄새의 지속 시간을 기록 - 최초로 넣을 때는 k + 1을 저장

// 행동을 시작할 때 모든 칸의 냄새 지속 시간을 -1 처리
// 모든 상어가 동시에 움직여야 하므로 각 상어별 다음 위치를 저장하는 배열을 따로 생성
// 이후 각 상어 별로 위치를 찾은 후, 방향 우선순위 순서대로 냄새가 없는 곳을 먼저 찾고, 없다면 내 냄새가 있는 곳을 찾아 다음 위치로 삼는다
// 상어는 반드시 한 칸씩 움직이기 때문에(= 내 주변 칸은 내 냄새가 남기에), 움직일 곳은 무조건 있음
// 이후 보드에 상어들을 모두 없앤 후, 번호 순서대로 보드들에 위치와 냄새 기록
// 번호 순서대로 하기에 이미 해당 위치에 상어가 마킹된 경우 우선순위에서 밀리는 큰 번호 상어들은 들어갈 수 없음 - 이 경우 상태를 -1로 만들어 사라지게 하고, 남은 상어 수를 줄인다
// 그렇게 돌리다가 상어 수가 1이 되면(1번 상어만 남으면) 탈출