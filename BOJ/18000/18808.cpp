// 스티커 붙이기
// https://www.acmicpc.net/problem/18808

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<vector<pr>>> stickers(k, vector<vector<pr>>(4));
	for (int t = 0; t < k; t++) {
		int r, c;
		cin >> r >> c;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				int p;
				cin >> p;
				if (p == 1)
					stickers[t][0].push_back({ i, j });
			}
		}
		for (int d = 1; d < 4; d++) {
			for (pr p : stickers[t][d - 1]) {
				pr b;
				b.first = p.second;
				b.second = -p.first;
				stickers[t][d].push_back(b);
			}
		}
	}

	vector<vector<bool>> board(n, vector<bool>(m));
	for (int t = 0; t < k; t++) {
		bool placed = false;
		int cr = -1, cx = -1, cy = -1;
		for (int r = 0; r < 4; r++) {
			for (int x = 0; x < n; x++) {
				for (int y = 0; y < m; y++) {
					placed = true;
					for (pr p : stickers[t][r]) {
						int xx = x + p.first;
						int yy = y + p.second;
						if (xx < 0 || yy < 0 || xx >= n || yy >= m || board[xx][yy]) {
							placed = false;
							break;
						}
					}
					if (placed) {
						cy = y;
						break;
					}
				}
				if (placed) {
					cx = x;
					break;
				}
			}
			if (placed) {
				cr = r;
				break;
			}
		}
		if (!placed)
			continue;
		for (pr p : stickers[t][cr]) {
			int xx = cx + p.first;
			int yy = cy + p.second;
			board[xx][yy] = true;
		}
	}
	int res = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (board[i][j])
				res++;
	cout << res << '\n';
}

// n*m 보드에 스티커들을 순서대로 아래와 같은 규칙으로 붙일 때, 보드에 채워진 스티커의 칸 수는?
// - 주어진 스티커를 보드를 벗어나거나 다른 스티커와 겹치지 않게 최대한 상단 -> 좌측의 위치에 붙인다
// - 만약 스티커를 붙일 수 없는 곳이면 시계방향으로 90도 회전시켜 부착을 시도하고, 360도를 모두 돌렸음에도 불가능하면 해당 스티커를 버린다

// 주어진 스티커는 반드시 차례대로 붙여야 함(순서를 바꿀 수 없음) - 따라서 스티커가 100개라도 부담없이 접근할 수 있음
// 스티커 입력이 들어오면, 편의를 위해 2차원 배열 형태가 아닌 좌표(pair)로 저장하기 - pair 1차원 순회로 블록을 더 쉽게 놓아볼 수 있음
// 또한 해당 좌표 배열을 각 회전각에 맞게 원점 기준으로 미리 회전하여 저장 - 시계방향 회전은 (y, -x)
// 따라서 스티커는 3차원 좌표 배열 안에 저장됨 - [번호][회전][칸]
// 이렇게 저장된 스티커들을 회전 -> x -> y 순으로 돌리며 현재 보드에 들어갈 수 있는지 확인
// 원점을 (x, y)으로 두고 시작하여, 만약 놓으려는 곳이 보드를 벗어나거나 다른 스티커가 있는 곳인 경우 바로 다음 경우로 이동
// 놓을 수 있는 곳을 찾으면 확정된 회전각 및 원점을 기록하고, 기록된 회전각 및 원점을 통해 해당 위치에 스티커를 놓는다
// 이 과정을 모든 스티커에 대해 적용한 뒤, 마지막으로 보드를 순회하며 채워진 칸 수를 세고 출력