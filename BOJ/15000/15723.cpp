// n단 논법
// https://www.acmicpc.net/problem/15723

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	vector<vector<char>> board(26, vector<char>());
	vector<bool> shown(26);
	for (int i = 0; i < n; i++) {
		char a, b;
		string _;
		cin >> a >> _ >> b;
		board[a - 'a'].push_back(b - 'a');
		shown[a - 'a'] = shown[b - 'a'] = true;
	}
	vector<vector<bool>> visit(26, vector<bool>(26));
	for (int i = 0; i < 26; i++) {
		if (!shown[i]) {
			continue;
		}
		queue<int> q;
		q.push(i);
		while (!q.empty()) {
			int p = q.front();
			q.pop();
			for (char j : board[p]) {
				if (!visit[i][j]) {
					visit[i][j] = true;
					q.push(j);
				}
			}
		}
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		char a, b;
		string _;
		cin >> a >> _ >> b;
		cout << (visit[a - 'a'][b - 'a'] ? "T" : "F") << '\n';
	}
}

// '모든 X는 Y' 형태의 전제들이 주어질 때, 주어진 결론에 대한 진위 출력하기

// 모든 a가 b고 모든 b가 c일 때, 모든 a는 c이다
// 이를 활용하여 '모든 X는 Y'를 X -> Y 형태의 방향그래프로 만든 후, 각 인자에 대해 bfs를 돌려 방문 여부(= 참 여부)를 확인한다
// 그러니까, 결론의 답은 곧 출발점에서 도착점까지 도달할 수 있느냐를 묻는 것