// 고인물이 싫어요
// https://www.acmicpc.net/problem/25187

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, t;
	cin >> n >> m >> t;
	vector<int> water(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> water[i];
	}
	vector<vector<int>> board(n + 1, vector<int>());
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		board[a].push_back(b);
		board[b].push_back(a);
	}
	vector<int> visit(n + 1, -1);
	for (int s = 1; s <= n; s++) {
		if (visit[s] != -1) {
			continue;
		}
		int zero = 0, one = 0;
		queue<int> q;
		vector<int> trail;
		visit[s] = 2;
		if (water[s] == 1) {
			one++;
		} else {
			zero++;
		}
		q.push(s);
		trail.push_back(s);
		while (!q.empty()) {
			int p = q.front();
			q.pop();
			for (int i : board[p]) {
				if (visit[i] == -1) {
					visit[i] = 2;
					if (water[i] == 1) {
						one++;
					} else {
						zero++;
					}
					q.push(i);
					trail.push_back(i);
				}
			}
		}
		for (int i : trail) {
			if (one > zero) {
				visit[i] = 1;
			} else {
				visit[i] = 0;
			}
		}
	}
	for (int i = 0; i < t; i++) { 
		int p;
		cin >> p;
		cout << visit[p] << '\n';
	}
}

// 청정수와 고인물 중 하나가 담긴 n개의 물탱크가 m개의 파이프로 연결되어 있고, 한 개의 물탱크에서는 연결된 물탱크들 중 청정수가 고인물보다 많으면 청정수를 얻을 수 있다고 할 때, 주어진 물탱크를 선택할 때 얻을 수 있는 물 종류 구하기

// 물통과 쿼리의 개수가 10만이므로 미리 모두 구해두는 게 유리할 것
// 구조 상 서로 연결된 물탱크는 모두 같은 물을 제공하기에, bfs로 물탱크 덩어리를 보고 판정하는 게 좋음
// 1번부터 순서대로 탐색되지 않은 물탱크에서 시작해 bfs로 탐색되지 않은 물탱크를 연결해주면서 청정수/고인물 개수도 함께 센다 - 탐색 기록도 보존한다
// 탐색이 끝나면 지금까지의 탐색 기록을 따라가며 청정수/고인물 개수에 따른 청정수/고인물 채취 여부 판정을 결과 배열에 넣어준다
// 그리고 쿼리 과정에서 결과 배열을 출력하면 되는 것
