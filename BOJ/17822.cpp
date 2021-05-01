// 원판 돌리기
// https://www.acmicpc.net/problem/17822

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, t;
	cin >> n >> m >> t;
	vector<vector<int>> board(n + 1, vector<int>(m));
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];
	int remain = n * m;
	for (int tt = 0; tt < t; tt++) {
		int z, d, k;
		cin >> z >> d >> k;
		if (remain == 0)
			continue;
		for (int r = z; r <= n; r += z) {
			for (int i = 0; i < k; i++) {
				int tmp;
				if (d == 0) {
					tmp = board[r][m - 1];
					for (int j = m - 1; j > 0; j--)
						board[r][j] = board[r][j - 1];
					board[r][0] = tmp;

				}
				else {
					tmp = board[r][0];
					for (int j = 0; j < m - 1; j++)
						board[r][j] = board[r][j + 1];
					board[r][m - 1] = tmp;
				}
			}
		}
		bool erased = false;
		vector<vector<bool>> erase(n + 1, vector<bool>(m));
		queue<pr> q;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] != 0 && !erase[i][j]) {
					q.push({ i, j });
					while (!q.empty()) {
						int x = q.front().first;
						int y = q.front().second;
						q.pop();
						for (int l = 0; l < 4; l++) {
							int xx = x + dx[l];
							int yy = (y + m + dy[l]) % m;
							if (xx <= 0 || xx > n)
								continue;
							if (board[x][y] == board[xx][yy] && !erase[xx][yy]) {
								if (!erase[x][y])
									erase[x][y] = true;
								erase[xx][yy] = true;
								erased = true;
								q.push({ xx, yy });
							}
						}
					}
				}
			}
		}
		if (erased) {
			for (int i = 1; i <= n; i++) {
				for (int j = 0; j < m; j++) {
					if (erase[i][j]) {
						board[i][j] = 0;
						remain--;
					}
				}
			}
		}
		else {
			double avg = 0;
			for (int i = 1; i <= n; i++)
				for (int j = 0; j < m; j++)
					avg += board[i][j];
			avg /= remain;
			for (int i = 1; i <= n; i++)
				for (int j = 0; j < m; j++)
					if (board[i][j] != 0)
						board[i][j] += (board[i][j] > avg ? -1 : (board[i][j] < avg ? 1 : 0));
		}
	}
	int res = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < m; j++)
			res += board[i][j];
	cout << res << '\n';
}

// m개의 칸에 자연수가 적힌 반지름이 다른 n개의 원판(1~n)이 크기 순서대로 과녁처럼 쌓여있다 - 그리고 이 원판 더미를 아래의 방식으로 회전하고자 한다
// 여기서 (x의 배수) 번째 원판(들)을 시계(반대)방향으로 k칸 돌린 후, 인접한 칸들의 같은 숫자들을 모두 지운다
// 만약 지울 숫자들이 없으면 남은 숫자들의 평균을 내어 평균 이상의 숫자는 -1, 이하의 숫자는 +1한다(평균과 정확히 맞으면 변경하지 않는다)
// 주어진 대로 회전을 마쳤을 때, 원판에 남은 숫자의 합은?

// 그저 시키는 대로 구현하면 문제 
// 원판 더미는 2차원 배열로 구성 - x축(원반)은 1부터 세고, y축(칸)은 나머지 연산을 위해 0부터 세기
// 이후 주어진 대로 회전 - 회전 횟수는 m 미만으로 주어지므로 이것 때문에 문제가 발생하지는 않음
// 원판 회전은 반복문을 이용해 구현 - 마지막/처음 숫자를 tmp로 빼고, 내 왼쪽/오른쪽에 있던 수를 내 자리로 복사한 다음 처음/마지막 자리를 tmp로 채우기
// 이후 인접 탐색 및 삭제는 bfs를 이용해 구현 - bfs 중에는 보드에서 지워질 곳을 체크만 하기
// 원판 더미의 모든 칸을 순회하면서 해당 칸이 지워졌거나 지워질 예정이 아니라면 bfs 탐색 시작, 같은 숫자를 가진 인접한 칸을 찾는다
// 만약 그러한 칸이 발견된 경우 해당 칸(과 지금 칸)에 지워질 예정이라는 표시를 하고 bfs 확장하기
// 이렇게 bfs 탐색 후 칸을 지우는 것이 확정됐다면 해당 칸들을 다시 순회하며 지워준다 - board[i][j] = 0
// 칸을 지우지 않는다면 모든 칸에 대한 평균을 구해, 조건에 따라 지워지지 않은 칸의 값을 증감한다
// 이 과정에서 지워지지 않은 칸들의 개수를 체크, 만약 모두 지워진 상태라면 입력만 받고 더 이상 연산하지 않기