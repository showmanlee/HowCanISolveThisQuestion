// 집배원 한상덕
// https://www.acmicpc.net/problem/2842

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;
int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<vector<char>> board(n, vector<char>(n));
	vector<vector<int>> height(n, vector<int>(n));
	int houses = 0;
	int sx = 0, sy = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'P') {
				sx = i;
				sy = j;
			}
			else if (board[i][j] == 'K')
				houses++;
		}
	}
	vector<int> candi;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> height[i][j];
			candi.push_back(height[i][j]);
		}
	}
	sort(candi.begin(), candi.end());
	candi.erase(unique(candi.begin(), candi.end()), candi.end());
	int left = 0, right = 0;
	int res = 987654321;
	while (left < candi.size()) {
		int remain = houses;
		vector<vector<bool>> visit(n, vector<bool>(n));
		queue<pr> q;
		if (height[sx][sy] >= candi[left] && height[sx][sy] <= candi[right]) {
			q.push({ sx, sy });
			visit[sx][sy] = true;
		}
		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			if (board[x][y] == 'K')
				remain--;
			for (int i = 0; i < 8; i++) {
				int xx = x + dx[i];
				int yy = y + dy[i];
				if (xx < 0 || yy < 0 || xx >= n || yy >= n || visit[xx][yy])
					continue;
				if (height[xx][yy] >= candi[left] && height[xx][yy] <= candi[right]) {
					visit[xx][yy] = true;
					q.push({ xx, yy });
				}
			}
		}
		if (remain == 0) {
			res = min(res, candi[right] - candi[left]);
			left++;
		}
		else if (right + 1 < candi.size())
			right++;
		else
			break;
	}
	cout << res << '\n';
}

// 각 칸마다 높이가 다른 n*n 지형에서 한 우체국에서 다른 집들에 상하좌우대각선으로 움직여 배송을 할 때, 탐색하는 최대 고도차의 최솟값은?

// 1981 배열에서 이동에서 도달해야 할 지점이 여러 개가 된 문제
// 따라서 원리 자체는 동일하게 접근(이분탐색 + bfs) - 여기서 모든 집에 도달했는지를 체크하는 것이 필요
// 이를 위해 보드를 받을 때 집의 개수 세어주기 - 물론 우체국 위치는 시작점으로 삼기
// 이후 1981의 방식대로 고도를 받으며 등장하는 모든 고도를 중복 제거하고 정렬한 뒤, 두 포인터 인덱스를 0으로 하여 탐색 시작
// 각 탐색마다 출발지에서 bfs를 돌리면서, 집이 있는 지역을 만나면 남은 집 수를 빼준다 - visit가 있기 때문에 중복으로 빠질 일은 없음
// 이렇게 모든 집을 방문한 경우 결과값 갱신 - 두 포인터 중 하나가 모든 고도를 만났다면 탐색 마치고 결과 출력하기