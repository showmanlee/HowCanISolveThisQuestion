// 벽 부수고 이동하기 4
// https://www.acmicpc.net/problem/16946

#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<vector<char>> board(n, vector<char>(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];
	vector<vector<int>> checker(n, vector<int>(m, -1));
	vector<int> sizes;
	int cnt = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == '0' && checker[i][j] == -1) {
				cnt++;
				queue<pr> q;
				q.push({ i, j });
				checker[i][j] = cnt;
				int s = 0;
				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					q.pop();
					s++;
					for (int t = 0; t < 4; t++) {
						int xx = x + dx[t];
						int yy = y + dy[t];
						if (xx < 0 || yy < 0 || xx >= n || yy >= m || board[xx][yy] == '1')
							continue;
						if (checker[xx][yy] == -1) {
							checker[xx][yy] = cnt;
							q.push({ xx, yy });
						}
					}
				}
				sizes.push_back(s);
			}
		}
	}
	vector<vector<int>> res(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == '1') {
				res[i][j] = 1;
				set<int> candi;
				for (int t = 0; t < 4; t++) {
					int xx = i + dx[t];
					int yy = j + dy[t];
					if (xx < 0 || yy < 0 || xx >= n || yy >= m)
						continue;
					if (checker[xx][yy] != -1)
						candi.insert(checker[xx][yy]);
				}
				for (int t : candi)
					res[i][j] += sizes[t];
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << (res[i][j] % 10);
		cout << '\n';
	}
}

// 벽이 있는 n*m 공간에서 특정 벽을 부쉈을 때 해당 위치에서 이동할 수 있는 칸의 개수(%10) 출력하기

// 보드가 그렇게 큰 것은 아니나, 각 벽마다 bfs를 돌리면 시간 초과
// 그 이유는 보드 전체(1000*1000)를 벽 개수만큼 돌릴 수도 있기 때문(100만^2 = ?)
// 벽이 하나 뚫리면 그 벽과 이어져있던 4방향의 빈칸을 통해 이동할 수 있는 칸의 개수가 결정됨
// 그렇다면 초기 상태에서 벽으로 인해 독립된 빈칸 덩어리들에 번호를 매기고, 그 덩어리들의 크기를 기록해두면 각각의 벽에 대해 bfs를 돌리지 않아도 사이즈를 알 수 있지 않을까
// 벽을 뚫었을 때 만나는 덩어리의 번호를 체크한 후, 해당 덩어리들의 크기의 합이 그 벽을 뚫을 때 접근할 수 있는 칸의 개수가 되는 것

// 보드를 받고, 해당 칸의 덩어리 번호가 무엇인지 판별하는 배열 생성(초기값은 -1) - 덩어리 번호의 크기를 나타내는 배열도 생성
// 보드의 각 칸에 대해 해당 칸이 빈 칸이고 아직 덩어리 번호가 매겨지지 않은 경우, 해당 칸을 기점으로 bfs를 돌리며 그 칸과 연결된 모든 빈칸을 한 덩어리로 만들고 크기 측정
// 이 과정이 완료되면 이번엔 보드의 각 칸에 대해 해당 칸이 벽이라면 그 칸의 상하좌우를 탐색해 만나는 덩어리들을 중복 걸러주는 set에 저장
// 이후 set에 들어가 있는 덩어리의 크기의 합을 결과 배열의 현재 칸에 더하기 - 여기서 현재 칸도 이동할 수 있는 칸이므로 +1
// 이렇게 모든 결과를 얻으면 결과 % 10 출력하기
