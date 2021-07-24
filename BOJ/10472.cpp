// 십자뒤집기
// https://www.acmicpc.net/problem/10472

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		string g1, g2, g3;
		cin >> g1 >> g2 >> g3;
		string g = g1 + g2 + g3;
		queue<string> q;
		q.push(".........");
		map<string, int> visit;
		visit["........."] = 0;
		while (!q.empty()) {
			string p = q.front();
			q.pop();
			if (p == g)
				break;
			for (int i = 0; i < 9; i++) {
				int x = i / 3;
				int y = i % 3;
				string pp = p;
				for (int j = 0; j < 4; j++) {
					int xx = x + dx[j];
					int yy = y + dy[j];
					if (xx < 0 || yy < 0 || xx >= 3 || yy >= 3)
						continue;
					pp[xx * 3 + yy] = (pp[xx * 3 + yy] == '.' ? '*' : '.');
				}
				pp[x * 3 + y] = (pp[x * 3 + y] == '.' ? '*' : '.');
				if (visit.count(pp) == 0) {
					visit[pp] = visit[p] + 1;
					q.push(pp);
				}
			}
		}
		cout << visit[g] << '\n';
	}
}

// 모든 칸이 흰 칸인 3*3 보드의 한 칸을 뒤집을 때 상하좌우 칸도 모두 뒤집어질 때, 목표 형태로 만들기 위해 필요한 동작 수는?

// 3*3 형태로 주어지는 보드를 일단 문자열 한 줄로 만들기
// 그리고 이를 이용해 bfs 돌리기 - visit는 map 형태로 관리
// 각 시도에서는 모든 칸에 대해 뒤집어본다 - 선택한 칸 상하좌우(에 위치한 인덱스)를 뒤집고, 현재 칸도 뒤집는다
// 이후 visit 안에 현재 인덱스의 값이 없다면(첫 방문), 체크해주고 큐에 삽입
// 그러다가 도착지에 도달하면 종료 후 출력