// 인내의 도미노 장인 호석
// https://www.acmicpc.net/problem/20165

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, r;
	cin >> n >> m >> r;
	vector<vector<int>> board(n + 1, vector<int>(m + 1));
	vector<vector<bool>> fliped(n + 1, vector<bool>(m + 1, false));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> board[i][j];
	int score = 0;
	for (int t = 0; t < r; t++) {
		int x, y;
		char d;
		cin >> x >> y >> d;
		queue<pr> q;
		int s = 0;
		if (!fliped[x][y])
			q.push({ x, y });
		fliped[x][y] = true;
		while (!q.empty()) {
			int ox = q.front().first;
			int oy = q.front().second;
			q.pop();
			s++;
			int xx = ox;
			int yy = oy;
			for (int i = 0; i < board[ox][oy] - 1; i++) {
				if (d == 'N')
					xx--;
				else if (d == 'S')
					xx++;
				else if (d == 'W')
					yy--;
				else if (d == 'E')
					yy++;
				if (xx <= 0 || yy <= 0 || xx > n || yy > m)
					continue;
				if (!fliped[xx][yy]) {
					fliped[xx][yy] = true;
					q.push({ xx, yy });
				}
			}
		}
		score += s;
		cin >> x >> y;
		fliped[x][y] = false;
	}
	cout << score << '\n';
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			cout << (fliped[i][j] ? 'F' : 'S') << ' ';
		cout << '\n';
	}
}

// 높이가 다른 도미노가 한 칸에 하나씩 놓인 n*m 보드에서 공격수와 수비수가 다음의 행동을 반복할 때, 공격수가 얻는 점수와 마지막 행동을 마친 후 보드 상태 구하기
// 공격수: 한 위치에 놓인 도미노를 특정 방향으로 쓰러뜨리고, 쓰러뜨린 수만큼 점수를 얻는다 - 높이가 2 이상인 도미노는 쓰러지는 방향의 (높이 - 1)개의 도미노를 넘어뜨릴 수 있다
// 수비수: 한 위치에 놓인 도미노를 다시 세운다
// 쓰러뜨리는 과정에서 이미 쓰러진 도미노는 다른 도미노에 영향을 주지 않는다

// 도미노의 높이를 저장하는 배열과 도미노의 상태를 저장하는 배열을 따로 운영해야 함
// 우선 높이가 1인 도미노는 다른 도미노에 영향을 미칠 수 없음에 주의
// 공격수가 도미노를 쓰러뜨리는 연쇄 과정에는 큐를 활용 - 현재 위치의 도미노가 세워져 있으면 도미노를 쓰러뜨린 후 큐 돌리기
// 큐 안에서 쓰러진 도미노에 대한 점수를 누적하고, 자신 앞에 (높이 - 1)개의 도미노에 대해 쓰러져있지 않다면 넘어뜨리고 큐에 넣는 과정을 반복
// 수비수가 도미노를 세울 때는 그냥 세우면 됨 - 조건 따질 필요 없이 '세우기'만 하면 됨
// 이렇게 턴을 돌린 후 최종 점수와 상태를 출력하면 됨