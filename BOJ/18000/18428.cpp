// 감시 피하기
// https://www.acmicpc.net/problem/18428

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int n, cnt, t;
char board[7][7];
pr candi[37], teacher[6];
int choice[3];
bool res;

void dfs(int idx, int c) {
	if (res)
		return;
	if (c == 3) {
		for (int i = 0; i < 3; i++)
			board[candi[choice[i]].first][candi[choice[i]].second] = 'O';
		for (int i = 0; i < t; i++) {
			for (int j = 0; j < 4; j++) {
				int x = teacher[i].first;
				int y = teacher[i].second;
				while (true) {
					x += dx[j];
					y += dy[j];
					if (x < 0 || y < 0 || x >= n || y >= n)
						break;
					if (board[x][y] == 'O')
						break;
					if (board[x][y] == 'S') {
						for (int i = 0; i < 3; i++)
							board[candi[choice[i]].first][candi[choice[i]].second] = 'X';
						return;
					}
				}
			}
		}
		res = true;
		return;
	}
	for (int i = idx; i < cnt; i++) {
		choice[c] = i;
		dfs(i + 1, c + 1);
	}
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	cnt = t = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'X')
				candi[cnt++] = { i, j };
			if (board[i][j] == 'T')
				teacher[t++] = { i, j };
		}
	}
	res = false;
	dfs(0, 0);
	cout << (res ? "YES" : "NO") << '\n';
}

// n*n 공간에서 상하좌우의 시야를 가진 선생님들의 눈에 띄지 않도록 학생들을 가려줄 1*1 장애물을 3개 세울 수 있을 때, 학생들을 모두 가릴 수 있는가?

// n이 최대 6까지이므로 특별한 판정 없이 브포로 충분히 접근할 수 있음
// 장애물을 놓을 수 있는 빈칸, 그리고 선생님의 위치를 별도의 배열에 저장하고, 3개를 고르는 dfs 브포를 돌림
// 장애물 위치를 결정하면 보드에 장애물을 깐 뒤, 모든 선생님에 대해 상하좌우로 학생을 볼 수 있는지 확인 - 장애물에 걸리거나 맵 밖에 나가면 정지, 학생을 발견하면 보드 원상복구 후 return
// 만약 return되지 않고 무사히 탐색을 마쳤다면 모든 학생이 숨었음을 의미, 결과값을 true로 변경 - 그 이후로는 더 이상 탐색하지 않도록