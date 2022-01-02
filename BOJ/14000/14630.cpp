// 변신로봇
// https://www.acmicpc.net/problem/14630

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<string> forms(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> forms[i];
	int m = forms[1].length();
	int s, e;
	cin >> s >> e;
	vector<int> dist(n + 1, 987654321);
	priority_queue<pr> pq;
	pq.push({ 0, s });
	dist[s] = 0;
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		if (cur == e)
			break;
		for (int i = 1; i <= n; i++) {
			if (i == cur)
				continue;
			int ncost = 0;
			for (int j = 0; j < m; j++) 
				ncost += (forms[cur][j] - forms[i][j]) * (forms[cur][j] - forms[i][j]);
			if (dist[i] > cost + ncost) {
				dist[i] = cost + ncost;
				pq.push({ -dist[i], i });
			}
		}
	}
	cout << dist[e] << '\n';
}

// 한 숫자 문자열이 다른 형태로 바뀌는 비용이 각 자릿수의 차의 제곱의 합일 때, 주어진 숫자 문자열들로 한 문자열에서 다른 문자열로 바꾸는데 드는 최소 비용은?
// 가중치가 다른 상황에서의 최단 거리는 다익스트라 - 그런데 각 상태간의 가중치를 계산으로 직접 알아내야 함
// 각 상태는 다른 모든 상태와 연결되어 있음 - 그리고 가중치도 직접 계산해야 할 뿐 정해져있음
// 계산하는 과정도 두 문자열의 각 문자를 순회하면 해당 문자의 차의 제곱을 누적해주면 됨
// 이런 상황인 것만 기억하고 평소처럼 다익스트라를 돌리면 OK