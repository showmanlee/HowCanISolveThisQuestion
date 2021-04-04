// 거짓말
// https://www.acmicpc.net/problem/1043

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

bool knows[51];
vector<int> person[51];
vector<int> party[51];

int main(void) {
	int n, m, p;
	cin >> n >> m >> p;
	for (int i = 0; i < p; i++) {
		int t;
		cin >> t;
		knows[t] = true;
	}
	for (int i = 1; i <= m; i++) {
		int o;
		cin >> o;
		for (int j = 0; j < o; j++) {
			int t;
			cin >> t;
			person[t].push_back(i);
			party[i].push_back(t);
		}
	}
	queue<int> q;
	for (int i = 1; i <= n; i++)
		if (knows[i])
			q.push(i);
	while (!q.empty()) {
		int t = q.front();
		q.pop();
		for (int i : person[t]) {
			for (int j : party[i]) {
				if (!knows[j]) {
					knows[j] = true;
					q.push(j);
				}
			}
		}
	}
	int res = 0;
	for (int i = 1; i <= m; i++) {
		bool flag = false;
		for (int j : party[i]) {
			if (knows[j]) {
				flag = true;
				break;
			}
		}
		if (!flag)
			res++;
	}
	cout << res << '\n';
}

// n명이 m개의 파티에 참석하려 한다. 이 때 진실을 알고 있는 사람들이 몇몇 파티에 참석할 때, 진실이 밝혀지지 않는 파티의 개수는?

// 어떤 사람이 진실을 알고 있는지 기록하는 knows와 함께, 어떤 사람이 참가한 파티 내역 / 어떤 파티에 참여하는 사람 내역을 따로 저장
// 이후 bfs를 통해 아는 사람들 확장시키기 - 처음 큐에는 최초로 알고 있는 사람만 저장
// 이후 큐 순회마다 그 사람이 간 파티에 참가한 사람들 중 모르는 사람을 알게 만든 후 큐에 삽입, 이 과정을 큐가 빌 때까지 반복하기
// 마지막에는 각 파티별 참가 인원을 돌면서, 파티에 진실을 아는 사람이 한 명도 없는 경우 결과에 추가