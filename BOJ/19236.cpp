// 청소년 상어
// https://www.acmicpc.net/problem/19236

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;
int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };

int board[5][5];
int status[17];
int res;

void dfs(int inx, int iny, int count) {
	int originBoard[4][4];
	int originStatus[17];
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			originBoard[i][j] = board[i][j];
	for (int i = 1; i <= 16; i++)
		originStatus[i] = status[i];
	
	count += board[inx][iny];
	int dir = status[board[inx][iny]];
	board[inx][iny] = -1;
	for (int t = 1; t <= 16; t++) {
		bool moved = false;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (board[i][j] == t) {
					for (int p = 0; p < 8; p++) {
						int x = i + dx[status[t]];
						int y = j + dy[status[t]];
						if (x >= 0 && y >= 0 && x < 4 && y < 4 && board[x][y] >= 0) {
							swap(board[i][j], board[x][y]);
							moved = true;
							break;
						}
						status[t] = (status[t] + 1) % 8;
					}
				}
				if (moved)
					break;
			}
			if (moved)
				break;
		}
	}
	
	int xx = inx;
	int yy = iny;
	while (true) {
		xx += dx[dir];
		yy += dy[dir];
		if (xx < 0 || yy < 0 || xx >= 4 || yy >= 4)
			break;
		if (board[xx][yy] > 0) {
			board[inx][iny] = 0;
			dfs(xx, yy, count);
			board[inx][iny] = -1;
		}
	}

	res = max(res, count);
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			board[i][j] = originBoard[i][j];
	for (int i = 1; i <= 16; i++)
		status[i] = originStatus[i];
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> board[i][j];
			cin >> status[board[i][j]];
			status[board[i][j]]--;
		}
	}
	res = 0;
	dfs(0, 0, 0);
	cout << res << '\n';
}

// 4*4 보드 안에 각자의 번호와 이동 방향(8방향)을 가진 물고기가 한 마리씩 있다
// 물고기들은 매 턴마다 번호 순서대로 자신의 방향으로 한 칸씩 이동한다
// - 만약 이동할 자리에 물고기가 있다면 해당 물고기와 자리를 바꾼다
// - 이동할 자리에 상어가 있거나 공간을 벗어난다면 다음 반시계 방향으로 이동을 시도한다
// - 최종적으로 이동할 자리가 없으면 그냥 있는다
// 이 보드 안에 상어가 들어와서 [0][0] 자리에 있는 물고기를 먹는다
// 상어는 물고기가 움직인 후, 아까 먹은 물고기의 방향대로 한 칸 이상 움직여 다른 물고기 하나를 먹을 수 있다
// - 빈 칸으로는 이동할 수 없고, 만약 이동할 수 있는 칸이 없으면 사냥을 멈춘다
// 이런 규칙으로 4*4 보드가 작동할 때, 상어가 먹는 물고기 번호의 합의 최댓값은?

// 백트래킹(재귀) 기반으로 접근할 수 있음 - 재귀 함수 들어가기 전에 초기 보드와 회전 상태를 따로 저장해준 뒤, 함수 마지막에 복구해주어야 함
// 4*4 보드에서 번호를 찾는 건 어렵지 않으니 물고기 상태를 저장하는 배열에는 회전 정보만 저장(입력 - 1하여 나머지 연산 활용)
// 함수 매개변수로는 현재 상어의 위치와 현재까지 쌓인 점수를 기록
// 함수에 들어가면 먼저 보드에 물고기를 상어(-1)로 바꿔줌
// 이후 번호 순서대로 보드에 있는 물고기를 이동시킨다(보드를 벗어나거나 상어가 있지 않으면 swap)
// 그 다음 상어를 이동시키는데, 만약 이동할 곳에 물고기가 있으면 상어가 있던 곳을 빈칸으로 만들고 재귀함수 진입
// 이동 과정을 마친 후에는 결과 갱신