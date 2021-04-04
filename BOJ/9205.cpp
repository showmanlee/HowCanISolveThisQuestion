// 맥주 마시면서 걸어가기
// https://www.acmicpc.net/problem/9205

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
typedef pair<int, int> pr;

int main(void) {
	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		int n;
		cin >> n;
		vector<pr> coord(n + 2);
		vector<vector<int>> graph(n + 2, vector<int>());
		vector<bool> visit(n + 2);
		for (int i = 0; i < n + 2; i++)
			cin >> coord[i].first >> coord[i].second;
		for (int i = 0; i < n + 2; i++) {
			for (int j = 0; j < n + 2; j++) {
				if (i != j && abs(coord[i].first - coord[j].first) + abs(coord[i].second - coord[j].second) <= 1000)
					graph[i].push_back(j);
			}
		}
		queue<int> q;
		q.push(0);
		visit[0] = true;
		while (!q.empty()) {
			int p = q.front();
			q.pop();
			for (int i : graph[p]) {
				if (!visit[i]) {
					visit[i] = true;
					q.push(i);
				}
			}
		}
		cout << (visit[n + 1] ? "happy" : "sad") << '\n';
	}
}

// 맥주병 20개를 들고 50m 당 맥주 하나를 까면서 집에서 락페까지 가야 하는데, 편의점에서 리필할 수 있다. 맥주가 마르기 전에 락페까지 갈 수 있는가?
// = 마지막으로 맥주를 사고 1000m(50*20) 안에 락페에 갈 수 있는가?
// 좌표만 주어지는 상황이니, 간선을 직접 만들어서 돌려야 한다 - 맨해튼 거리가 1000 이하라면 간선을 만들고, 그렇지 않으면 간선을 만들지 않는다(못 가니까)
// x, y 좌표를 모두 입력받고, n^2를 돌리며 1000 이하인 경우에 그래프에 간선을 긋는다(2차원 vector)
// 그렇게 만들어진 그래프를 바탕으로 bfs를 돌리며 도달 여부 확인 - 그게 정답