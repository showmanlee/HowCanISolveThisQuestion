// 성곽
// https://www.acmicpc.net/problem/2234

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;
int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { -1, 0, 1, 0 };

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> board(m, vector<int>(n)), room(m, vector<int>(n, -1));
	vector<int> sizes;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> board[i][j];
	int idx = -1;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (room[i][j] == -1) {
				idx++;
				int s = 0;
				queue<pr> q;
				q.push({ i, j });
				room[i][j] = idx;
				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					q.pop();
					s++;
					for (int t = 0; t < 4; t++) {
						if ((board[x][y] >> t) % 2 == 1)
							continue;
						int xx = x + dx[t];
						int yy = y + dy[t];
						if (xx < 0 || yy < 0 || xx >= m || yy >= n)
							continue;
						if (room[xx][yy] == -1) {
							room[xx][yy] = idx;
							q.push({ xx, yy });
						}
					}
				}
				sizes.push_back(s);
			}
		}
	}
	cout << sizes.size() << '\n';
	cout << *max_element(sizes.begin(), sizes.end()) << '\n';
	int res = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (i != m - 1 && room[i][j] != room[i + 1][j])
				res = max(res, sizes[room[i][j]] + sizes[room[i + 1][j]]);
			if (j != n - 1 && room[i][j] != room[i][j + 1])
				res = max(res, sizes[room[i][j]] + sizes[room[i][j + 1]]);
		}
	}
	cout << res << '\n';
}

// m*n 형태의 성의 각 칸에 세워진 벽의 방향이 비트(남동북서)로 주어질 때, 방의 개수 / 가장 넓은 방 / 벽 하나를 제거하여 얻을 수 있는 가장 큰 방의 크기 구하기

// 방의 수와 크기를 재기 위해 bfs 영역 탐색 사용 - 다만 각 칸마다 세워진 벽에 따라 이동 방향이 제한됨
// 여기서 room 배열은 방의 번호를 적는데 활용됨 - 그리고 적힌 방의 번호는 그대로 sizes 배열의 인덱스가 되어 해당 방의 크기를 기록하는데 사용됨
// 모든 칸을 순회하며 아직 방 번호가 배정되지 않았다면 해당 지점에서 시작해 bfs를 돌림 - 돌리면서 크기도 측정
// bfs 순회 방향은 비트 순서에 맞춰 서북동남 순으로 - 시프트를 활용, 해당되는 비트가 0이라면 탐색을 진행
// 그 외에는 평범한 bfs로 방에 소속되는 칸에 인덱스를 찍어준 뒤, 잰 크기를 sizes 배열에 삽입

// 모든 순회를 마치고 모든 칸에 방 번호가 배정되면 결과 출력하기 - 크기와 가장 큰 방 출력
// 그리고 모든 칸의 인접한 칸 쌍들을 순회하며 두 칸의 방 번호가 다를 경우(= 사이에 벽이 있을 경우) 해당 벽을 제거한 방 크기(= 내 방 크기 + 옆 방 크기)를 구하여 결과값에 갱신 후 출력하기

// algorithm 안에 있는 max_element와 min_element는 해당 iterator 범위 내 가장 큰/작은 값의 위치를 iterator로 반환한다
// 이를 포인터처럼 사용하여 배열 내 가장 큰 값/작은 값을 쉽게 확인할 수 있음 - 정렬 없이!