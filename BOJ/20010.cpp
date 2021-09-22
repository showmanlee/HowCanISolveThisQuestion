// 악덕 영주 혜유
// https://www.acmicpc.net/problem/20010

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;
typedef pair<pr, int> prr;

int group[1001];

int finding(int p) {
	if (p == group[p])
		return p;
	return group[p] = finding(group[p]);
}

void unioning(int a, int b) {
	int ga = finding(a);
	int gb = finding(b);
	if (ga < gb)
		group[gb] = ga;
	else
		group[ga] = gb;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		group[i] = i;
	vector<prr> board(m);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		board[i] = { {a, b}, c };
	}
	vector<vector<pr>> mst(n);
	sort(board.begin(), board.end(), [](prr a, prr b) {return a.second < b.second; });
	int cnt = 0;
	long long resa = 0;
	for (prr p : board) {
		int a = p.first.first;
		int b = p.first.second;
		int len = p.second;
		if (finding(a) == finding(b))
			continue;
		unioning(a, b);
		resa += len;
		mst[a].push_back({ b, len });
		mst[b].push_back({ a, len });
		cnt++;
		if (cnt == n - 1)
			break;
	}
	long long resb = 0;
	for (int t = 0; t < n; t++) {
		vector<long long> dist(n, -1);
		long long r = 0;
		queue<int> q;
		q.push(t);
		dist[t] = 0;
		while (!q.empty()) {
			int p = q.front();
			q.pop();
			for (pr pp : mst[p]) {
				if (dist[pp.first] == -1) {
					dist[pp.first] = dist[p] + pp.second;
					r = max(dist[pp.first], r);
					q.push(pp.first);
				}
			}
		}
		resb = max(resb, r);
	}
	cout << resa << '\n' << resb << '\n';
}

// n개의 마을 중 두 마을을 잇는 비용이 주어질 때, 모든 마을을 잇는데 드는 최소 비용과 그 상황에서 임의의 두 마을 간 최단 거리가 최대가 되는 경우의 거리 구하기

// MST를 구하는데, 여기에 그치지 않고 만들어진 MST를 직접 순회해야 한다
// 우선 마을을 연결하는 과정 - MST 생성 과정은 일반적인 크루스칼로 처리
// 여기서 MST 간선의 합을 구하는 것 뿐만이 아니라, 실제로 2차원 vector 기반으로 보드를 하나 그려줘야 한다
// 이렇게 얻은 보드를 기반으로 bfs로 보드를 순회해 최단 거리의 최댓값을 구한다 - 노드 수가 1000개까지이므로 모든 노드에서 bfs를 돌려도 문제없음