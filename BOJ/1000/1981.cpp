// 배열에서 이동
// https://www.acmicpc.net/problem/1981

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<vector<int>> board(n, vector<int>(n));
	vector<int> candi;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			candi.push_back(board[i][j]);
		}
	}
	sort(candi.begin(), candi.end());
	candi.erase(unique(candi.begin(), candi.end()), candi.end());
	int left = 0, right = 0;
	int res = 987654321;
	while (left < candi.size()) {
		vector<vector<bool>> visit(n, vector<bool>(n));
		queue<pr> q;
		if (board[0][0] >= candi[left] && board[0][0] <= candi[right]) {
			visit[0][0] = true;
			q.push({ 0, 0 });
		}
		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			if (x == n - 1 && y == n - 1)
				break;
			for (int i = 0; i < 4; i++) {
				int xx = x + dx[i];
				int yy = y + dy[i];
				if (xx < 0 || yy < 0 || xx >= n || yy >= n || visit[xx][yy])
					continue;
				if (board[xx][yy] >= candi[left] && board[xx][yy] <= candi[right]) {
					visit[xx][yy] = true;
					q.push({ xx, yy });
				}
			}
		}
		if (visit[n - 1][n - 1]) {
			res = min(res, candi[right] - candi[left]);
			left++;
		}
		else if (right < candi.size())
			right++;
		else
			break;
	}
	cout << res << '\n';
}

// 각 칸마다 숫자가 적인 n*n 보드에서 좌측 상단에서 우측 하단으로 이동할 때, 밟게 되는 숫자의 최댓값과 최솟값의 차의 최솟값은?

// 우선 출발지가 최소/최대라는 보장은 없음 - 따라서 차를 정해놓고 순회하는 것은 불가능
// 그렇다고 등장 범위를 n^2로 두고 돌리는 것도 불가능 - 100*100*100*100 = ?
// 따라서 범위에 대해 이분 탐색을 도입해야 하는데 - 최솟값과 최댓값을 설정할 수 있도록
// 확실한 처리를 위해 그냥 돌리지 않고 등장한 수를 모두 기록해 정렬하고 중복을 제거한 배열을 활용, 해당 배열에 2개의 포인터를 둔다
// 두 포인터는 모두 시작점이 0 - 각 포인터는 bfs 과정에서 밟을 수 있는 수의 범위를 나타내고, 두 포인터가 가리키는 값의 차가 우리가 원하는 결과값
// 이렇게 포인터 범위 안에서 bfs 탐색이 가능하다면 왼쪽 포인터를 옮기고, 불가능하다면 오른쪽 포인터를 옮긴다 - 만약 두 포인터 중 하나가 범위를 벗어난 경우 종료
// bfs 탐색은 일반적인 방식과 동일하나, 밟은 칸이 포인터 값 범위 내에 있어야 진행 가능 - 출발지 역시 포인터 값 범위 안에 있어야 함에 주의
// bfs 탐색을 정상적으로 마친 경우에는 현재 포인터가 가리키는 값의 차를 결과값에 갱신 - 어떻게 가든 결과값은 갱신됨