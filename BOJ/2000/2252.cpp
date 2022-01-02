// 줄 세우기
// https://www.acmicpc.net/problem/2252

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> route(n + 1, vector<int>());
	vector<int> div(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		route[a].push_back(b);
		div[b]++;
	}
	queue<int> q;
	for (int i = 1; i <= n; i++)
		if (div[i] == 0)
			q.push(i);
	while (!q.empty()) {
		int p = q.front();
		q.pop();
		cout << p << ' ';
		for (int i : route[p]) {
			div[i]--;
			if (div[i] == 0)
				q.push(i);
		}
	}
	cout << '\n';
}

// n명의 학생 중 일부 학생들의 키를 비교한 것이 주어졌을 때, 이를 바탕으로 줄을 세운 결과 출력하기
// 줄 세우기는 위상 정렬로 풀 수 있는 문제 - div가 0이라면 현재 가장 작은 친구이니 앞에 세워야 함(출력해야 함)
// div는 내 앞에 있는 사람들 수 - a-b로 받을 때 b의 div가 ++
// route는 나로 인해 div가 줄어드는 친구들을 저장, queue에서 내 차례에 도달했을 경우 route에 있는 나머지 친구들의 div--

// solved.ac 골드 1 도달 성공! - 플레까지 199점 남았어요