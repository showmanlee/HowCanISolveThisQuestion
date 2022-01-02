// 이모티콘
// https://www.acmicpc.net/problem/14226

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;
typedef pair<pr, int> prr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int s;
	cin >> s;
	vector<vector<bool>> visit(2001, vector<bool>(2001));
	queue<prr> q;
	q.push({ {1, 0}, 0 });
	visit[1][0] = true;
	int res = 987654321;
	while (!q.empty()) {
		int p = q.front().first.first;
		int c = q.front().first.second;
		int t = q.front().second;
		q.pop();
		if (p == s) {
			res = min(res, t);
			continue;
		}
		if (!visit[p][p]) {
			visit[p][p] = true;
			q.push({ {p, p}, t + 1 });
		}
		if (p < s && !visit[p + c][c]) {
			visit[p + c][c] = true;
			q.push({ {p + c, c}, t + 1 });
		}
		if (p > 0 && !visit[p - 1][c]) {
			visit[p - 1][c] = true;
			q.push({ {p - 1, c}, t + 1 });
		}
	}
	cout << res << '\n';
}

// 화면에 이모티콘이 하나 찍혀있고 클립보드가 빈 상태에서 '전체 복사', '붙여넣기', '하나 삭제' 등 3가지 행동을 하여 이모티콘을 s개로 만드는 최소 시간은?
// 한 행동을 하는 데는 똑같이 1초가 걸리고 최소 시간을 찾는다 - bfs로 접근 가능
// visit는 2차원으로 관리 - 화면의 개수, 클립보드의 개수
// visit의 크기는 최대 2001로 두기 - 물론 큐 안에서 화면의 개수가 목표 개수를 넘어선 경우라면 붙여넣기를 하지는 않을 것
// 이것들만 고려하면 기본적인 bfs로 접근 가능