// 문명
// https://www.acmicpc.net/problem/14868

#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int group[100001];

int finding(int p) {
	if (p == group[p])
		return p;
	return group[p] = finding(group[p]);
}

void unioning(int a, int b) {
	int ga = finding(a), gb = finding(b);
	if (ga < gb)
		group[gb] = ga;
	else
		group[ga] = gb;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;
	vector<vector<int>> board(n + 1, vector<int>(n + 1));
	queue<pr> q, tq;
	for (int i = 1; i <= k; i++) {
		group[i] = i;
		int a, b;
		cin >> a >> b;
		board[a][b] = i;
		tq.push({ a, b });
	}
	int res = 0;
	while (true) {
		while (!tq.empty()) {
			int x = tq.front().first;
			int y = tq.front().second;
			tq.pop();
			q.push({ x, y });
			for (int i = 0; i < 4; i++) {
				int xx = x + dx[i];
				int yy = y + dy[i];
				if (xx <= 0 || yy <= 0 || xx > n || yy > n || board[xx][yy] == 0)
					continue;
				if (board[xx][yy] != board[x][y])
					unioning(board[x][y], board[xx][yy]);
			}
		}
		set<int> verify;
		for (int i = 1; i <= k; i++)
			verify.insert(finding(i));
		if (verify.size() == 1)
			break;
		res++;
		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int xx = x + dx[i];
				int yy = y + dy[i];
				if (xx <= 0 || yy <= 0 || xx > n || yy > n || board[xx][yy] != 0)
					continue;
				board[xx][yy] = board[x][y];
				tq.push({ xx, yy });
			}
		}
	}
	cout << res << '\n';
}

// n*n 보드에 서로 다른 문명들이 한 칸씩 발상하고, 이 문명들이 매년 상하좌우 한칸씩 확장되며 영역이 인접하거나 겹치면 하나의 문명으로 합쳐질 때, 모든 문명이 하나로 겹치는 시점은?

// bfs + union-find - bfs 탐색 결과에 따라 union-find를 해줘야 하는 문제
// 일단 들어오는 문명에 고유 번호를 붙이고, board에도 해당 문명의 번호를 적어주기
// bfs 큐는 2개를 운영 - 인접 확인용 큐, 확장용 큐
// 처음에는 확인용 큐에 발상 위치들을 삽입하고, 확인용 큐부터 돌려주기 - 처음 들어온 곳이 접해있을 수도 있음
// 확인용 큐에서는 해당 위치와 접한 문명을 확인하고, 두 문명이 접한 경우 두 문명을 하나로 합쳐주는 과정을 진행 - 그러면서 확장용 큐에 확인용 큐에 들어간 좌표를 삽입
// 이후 set을 이용해 현재까지 존재하는 그룹의 수를 확인한 후, 하나만 남으면 해당 시점 출력 - 그렇지 않으면 시점 늘리기
// 그리고 확장용 큐를 돌리며 일반적인 bfs 영역 확장처럼 영역을 확장한 후 확장한 지점을 확인용 큐에 삽입 - 이 과정을 그룹이 하나만 남을 때까지 반복

// 풀리는 속도가 느리긴 하지만 풀리긴 함 - 그렇다고 2000*2000 보드라 보드 전체를 순회하며 번호를 고치기에는 어려움