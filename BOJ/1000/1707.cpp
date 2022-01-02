// 이분 그래프
// https://www.acmicpc.net/problem/1707

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int k;
	cin >> k;
	for (int t = 0; t < k; t++) {
		int v, e;
		cin >> v >> e;
		vector<vector<int>> board(v + 1);
		for (int i = 0; i < e; i++) {
			int a, b;
			cin >> a >> b;
			board[a].push_back(b);
			board[b].push_back(a);
		}
		vector<int> color(v + 1);
		for (int m = 1; m <= v; m++) {
			if (color[m] == 0) {
				color[m] = 1;
				queue<int> q;
				q.push(m);
				while (!q.empty()) {
					int p = q.front();
					q.pop();
					for (int i : board[p]) {
						if (color[i] == 0) {
							color[i] = (color[p] == 1 ? 2 : 1);
							q.push(i);
						}
					}
				}
			}
		}
		bool res = true;
		for (int i = 1; i <= v; i++) {
			for (int j : board[i]) {
				if (color[i] == color[j]) {
					res = false;
					break;
				}
			}
			if (!res)
				break;
		}
		cout << (res ? "YES" : "NO") << '\n';
	}
}

// 주어진 그래프가 이분 그래프인지 판정하기
// 이분 그래프는 주어진 노드들을 두 그룹으로 나눴을 때 간선이 두 그룹 간에만 있는 그래프 - 한 그룹의 두 노드를 이으면 안 됨
// 그러니까, 한 노드와 연결된 다른 노드들은 나와 색깔이 달라야 한다
// 1번 노드부터 색을 칠한 뒤, bfs로 순회하면서 자신과 연결되었지만 색이 안 칠해진 노드에 반대 색깔을 칠한다
// - 모든 노드가 연결되었다는 보장이 없기에(연결되지 않은 노드는 이분 그래프 판정에 참여하지 않음), 모든 노드에서 bfs가 시작될 수 있도록 조치 필요
// 이후 노드를 다시 순회하면서 같은 색으로 연결된 간선 발견 시 이분 그래프 아님 판정