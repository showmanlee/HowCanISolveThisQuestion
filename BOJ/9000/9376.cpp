// 탈옥
// https://www.acmicpc.net/problem/9376

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;
typedef pair<int, pr> prr;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		int n, m;
		cin >> n >> m;
		vector<vector<char>> board(n + 2, vector<char>(m + 2, '.'));
		vector<pr> person;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> board[i][j];
				if (board[i][j] == '$')
					person.push_back({ i, j });
			}
		}
		person.push_back({ 0, 0 });
		vector<vector<vector<int>>> dist(3, vector<vector<int>>(n + 2, vector<int>(m + 2, 98765432)));
		for (int r = 0; r < 3; r++) {
			priority_queue<prr> pq;
			pq.push({ 0, person[r] });
			dist[r][person[r].first][person[r].second] = 0;
			while (!pq.empty()) {
				int len = -pq.top().first;
				int x = pq.top().second.first;
				int y = pq.top().second.second;
				pq.pop();
				for (int i = 0; i < 4; i++) {
					int xx = x + dx[i];
					int yy = y + dy[i];
					if (xx < 0 || yy < 0 || xx > n + 1 || yy > m + 1 || board[xx][yy] == '*')
						continue;
					int nlen = len + (board[xx][yy] == '#' ? 1 : 0);
					if (dist[r][xx][yy] > nlen) {
						dist[r][xx][yy] = nlen;
						pq.push({ -nlen, {xx, yy} });
					}
				}
			}
		}
		int res = 987654321;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (board[i][j] != '*') {
					int ret = 0;
					for (int r = 0; r < 3; r++)
						ret += dist[r][i][j];
					if (board[i][j] == '#')
						ret -= 2;
					res = min(res, ret);
				}
			}
		}
		cout << res << '\n';
	}
}

// 감옥 밖의 누군가가 죄수 2명을 탈옥하기 위해 잠긴 문들이 있는 감옥에 잠입할 때, 최소로 열어야 하는 문의 개수는?

// 어차피 지금 문제는 거리가 중요한 것이 아닌 문을 따는 횟수가 중요함
// 바깥에서 들어가는 누군가와 안에서 나오려는 죄수들이 한 곳에 만나면 탈출할 수 있음 - 여기서 죄수도 문을 딸 수 있다고 생각하기(어차피 누군가와 만나면 죄수 경로의 문이 다 열릴 것)
// 따라서 바깥의 누군가와 죄수는 모두 똑같은 사람으로 간주할 수 있음 - 따라서 감옥 '밖' 위치와 죄수 2명의 위치를 모두 한 배열에 정리
// 감옥 '밖'은 보드의 외곽을 빈칸으로 두른 뒤, 0,0 위치에서 출발한다고 계산하자 - 반복하지만 지금은 총 거리가 중요한 게 아니라 이렇게 생각할 수도 있음
// 각 칸마다 문을 최소로 열고 방문해야 하므로 탐색은 다익스트라로 진행 - 다익스트라로 각 칸으로 갈 때 몇 개의 문을 열어야 하는지 기록
// 이후, 모든 칸을 순회하며 세 사람이 해당 칸에 도달하기 위해 연 문 합이 가장 작은 것이 답
// 단, 여기서 문이 있는 칸이었을 경우 해당 칸에 도달하기 위해 세 사람 모두 문을 한 번씩 열었으므로 합에서 -2를 해줘야 함에 주의

// 여기서 배운 테크닉 하나 - 거리가 중요하지 않을 떄는 보드 외곽을 빈칸으로 둘러서 '임의의 위치'에서 출발한 효과를 볼 수도 있다