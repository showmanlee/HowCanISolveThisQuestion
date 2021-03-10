// 게임 개발
// https://www.acmicpc.net/problem/1516

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> dim(n + 1), times(n + 1), res(n + 1);
	vector<vector<int>> route(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> times[i];
		while (true) {
			int b;
			cin >> b;
			if (b == -1)
				break;
			else {
				route[b].push_back(i);
				dim[i]++;
			}
		}
	}
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (dim[i] == 0) {
			q.push(i);
			res[i] = times[i];
		}
	}
	while (!q.empty()) {
		int p = q.front();
		q.pop();
		for (int i : route[p]) {
			res[i] = max(res[p] + times[i], res[i]);
			dim[i]--;
			if (dim[i] == 0)
				q.push(i);
		}
	}
	for (int i = 1; i <= n; i++)
		cout << res[i] << '\n';
}

// 각 건물의 건설 소요 시간과 선행 건물 목록이 주어질 때, 각 건물 건설에 필요한 최소 시간 출력하기
// 테크트리 문제는 위상정렬 문제 - 테크트리에서 자신 위에 있는 건물 수를 기록하여, 그 건물 수가 0인 건물부터 차례로 계산하기
// 반대로 테크트리를 2차원 vector로 작성할 때는 선행 건물에 후행 건물들을 기록한다
// ACM Craft와 달리 모든 건물을 확인할 필요가 있고, 테크트리가 간선이 아닌 건물 단위로 주어짐