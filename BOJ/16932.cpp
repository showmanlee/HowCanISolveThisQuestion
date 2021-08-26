// 모양 바꾸기
// https://www.acmicpc.net/problem/16932

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
	vector<vector<int>> board(n, vector<int>(m)), visit(n, vector<int>(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];
	int idx = 0;
	vector<int> sizes(1);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 1 && visit[i][j] == 0) {
				idx++;
				visit[i][j] = idx;
				queue<pr> q;
				q.push({ i, j });
				int size = 1;
				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					q.pop();
					for (int t = 0; t < 4; t++) {
						int xx = x + dx[t];
						int yy = y + dy[t];
						if (xx < 0 || yy < 0 || xx >= n || yy >= m || board[xx][yy] == 0)
							continue;
						if (visit[xx][yy] == 0) {
							visit[xx][yy] = idx;
							q.push({ xx, yy });
							size++;
						}
					}
				}
				sizes.push_back(size);
			}
		}
	}
	int res = 0;
	for (int i : sizes)
		res = max(i, res);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 0) {
				set<int> candi;
				int ret = 1;
				for (int t = 0; t < 4; t++) {
					int xx = i + dx[t];
					int yy = j + dy[t];
					if (xx < 0 || yy < 0 || xx >= n || yy >= m)
						continue;
					candi.insert(visit[xx][yy]);
				}
				for (int p : candi)
					ret += sizes[p];
				res = max(res, ret);
			}
		}
	}
	cout << res << '\n';
}


// 0과 1이 적힌 n*m 보드에서 숫자 하나를 바꿔 만들 수 있는 인접한 1로 구성된 모양 크기의 최댓값 구하기

// bfs 크기 구하기 + 브루트포스
// 다만 보드 크기가 100만이므로, 숫자를 하나씩 바꿔가며 bfs를 매번 돌릴 수는 없음
// 그렇다면 어떻게? - 초기 상태에서 존재하는 모양들의 크기를 미리 구해두자
// 이를 위해 처음에 방문하지 않은 모든 1에 대해 bfs를 돌리며 인접한 1들을 모두 덩어리로 묶어줘야 함 - visit 배열을 통해 각 모양별 인덱스 부여
// 그리고 그렇게 부여된 인덱스를 바탕으로 측정된 모양의 크기를 별도의 배열에 저장 - 0은 그 칸이 0임을 의미하므로 크기도 0
// 이후 모든 0에 대해 1로 바꿨을 때 이어지는 모양의 크기를 구한다 - 그 전에 바꿔서 모양 크기를 확장할 수 없을 수도 있으니 이미 구해진 크기들 중 최댓값을 결과값으로 삼는다
// 바뀐 칸의 상하좌우에 존재하는 모양 인덱스를 중복 없이 습득한 후, 해당 인덱스에 대응하는 모양의 크기 합 + 1을 결과값과 비교해 갱신
// 모양 크기의 최댓값을 구하고자 하니, 오히려 크기를 줄이는 1->0 변경은 고려할 필요 없음
// 이 과정으로 얻어낸 결과값이 답