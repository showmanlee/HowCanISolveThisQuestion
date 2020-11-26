// Metroidvania Extreme
// https://www.acmicpc.net/problem/20130

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;

int main(void) {
	int n, m;
	cin >> n >> m;
	vector<vector<char>> board(n + 1, vector<char>(m + 1));
	vector<vector<bool>> visit(n + 1, vector<bool>(m + 1));
	pr d[4] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
	vector<pr> route, brk;
	vector<vector<pr>> locks(26);
	queue<pr> q;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			cin >> board[i][j];
			if (board[i][j] == '@') {
				q.push({ i, j });
				board[i][j] = '*';
				visit[i][j] = true;
			}
			if (board[i][j] >= 'A' && board[i][j] <= 'Z')
				locks[board[i][j] - 'A'].push_back({ i, j });
		}
	while (!q.empty()) {
		pr cur = q.front();
		q.pop();
		if (find(route.begin(), route.end(), cur) == route.end())
			route.push_back(cur);
		if (board[cur.first][cur.second] == '!')
			break;
		else if (board[cur.first][cur.second] >= 'a' && board[cur.first][cur.second] <= 'z') {
			int k = board[cur.first][cur.second] - 'a';
			for (pr l : locks[k])
				board[l.first][l.second] = '*';
		}
		for (int i = 0; i < 4; i++) {
			pr go = cur;
			go.first += d[i].first;
			go.second += d[i].second;
			if (go.first <= 0 || go.second <= 0 || go.first > n || go.second > m)
				continue;
			if (!visit[go.first][go.second] && board[go.first][go.second] != '#' && !(board[go.first][go.second] >= 'A' && board[go.first][go.second] <= 'Z')) {
				q.push(go);
				visit[go.first][go.second] = true;
			}
			if (board[go.first][go.second] >= 'A' && board[go.first][go.second] <= 'Z' && find(brk.begin(), brk.end(), cur) == brk.end())
				brk.push_back(cur);
		}
		if (q.empty()) {
			for (pr b : brk)
				q.push(b);
			brk.clear();
		}
	}

	cout << route.size() << '\n';
	for (pr p : route)
		cout << p.first << ' ' << p.second << '\n';
}

/* RPG Extreme의 후속작 - 그러나 난이도 대폭 감소(제작진 공식)
 * 보드의 크기와 보드에 있는 것들이 주어질 때, 규칙에 맞춰 탐색한 보드 좌표를 아무 거나(최단 아니어도 됨) 출력하라
 *
 * - 규칙
 *  1. 상하좌우로 한 칸씩 이동 - 단, 이전에 지나갔던 곳이라면 순간이동 가능
 *  2. 벽(#)이나 맵 밖으로는 이동 불가
 *  3. 목표 지점(!) 도달 시 게임 종료
 *  4. 열쇠(a~z)를 얻어 자물쇠(A~Z)를 열 수 있고, 열쇠는 사라지지 않음
 *	 - 대응하는 열쇠나 자물쇠가 없을 수도 있음
 *  5. 반드시 목표 지점으로 갈 수 있음
 *
 * - 보드 범례
 *  # - 벽
 *  @ - 시작
 *  ! - 종료
 *  * - 없음
 *  a-z - 열쇠
 *  A-Z - 자물쇠
 */

// 저번에는 비문학급 구현 문제였으나 지금은 자물쇠-열쇠 개념이 있는 BFS 문제
// 자물쇠 위치를 알파벳별로 정리해두고, 자물쇠 때문에 막힌 경험이 있는 곳일 경우 따로 저장해둬서 나중에 큐 비었을 때 채워넣기
// 경로는 중복 좌표 없이 저장해야 함에 주의 - find 사용
// visit 갱신은 큐에 빼는 순간이 아닌 넣는 순간에 해야 시간을 절약할 수 있다