// 회의준비
// https://www.acmicpc.net/problem/2610

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int group[101];
vector<int> committee[101];

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

	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		group[i] = i;
	vector<vector<int>> dist(n + 1, vector<int>(n + 1, 987654321));
	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		unioning(a, b);
		dist[a][b] = dist[b][a] = 1;
	}
	for (int i = 1; i <= n; i++) {
		committee[finding(i)].push_back(i);
		dist[i][i] = 0;
	}
	for (int t = 1; t <= n; t++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (dist[i][j] > dist[i][t] + dist[t][j])
					dist[i][j] = dist[i][t] + dist[t][j];
	vector<int> res;
	for (vector<int>& comm : committee) {
		if (comm.empty())
			continue;
		int p = comm[0];
		int len = 987654321;
		for (int i : comm) {
			int t = 0;
			for (int j : comm)
				t = max(dist[i][j], t);
			if (len > t) {
				len = t;
				p = i;
			}
		}
		res.push_back(p);
	}
	sort(res.begin(), res.end());
	cout << res.size() << '\n';
	for (int i : res)
		cout << i << '\n';
}

// 사람들의 관계도가 주어진다 - 여기서 아는 사람들끼리는 무조건 한 위원회로 뭉쳐야 하고, 위원회 참석자는 대표에게 의견을 전달할 때 아는 사람을 통해서만 전달할 수 있다
// 이 때, 각 위원회 참석자가 의견을 대표에게 전달하기 위해 거치는 사람 수의 최대가 최소가 되도록 각 위원회의 대표 선출하기

// 저 말이 '거치는 사람(= 거리)의 합'을 의미하는 것이 아님에 주의 - '거리의 최댓값이 최소'가 되어야 하는것(반례)
// 전체에 대한 거리 측정을 위한 플로이드 + 위원회 덩어리 판별을 위한 Union-find
// 우선 관계를 받으면서 union-find로 그룹화하면서 플로이드 맵에 관계 그려주기 - 그리고 그렇게 얻은 그룹 번호를 통해 해당 번호의 위원회 배열에 사람 삽입
// 이후 비어있지 않은 위원회 배열에 대해 해당 위원회에 속한 사람 중 거리 최댓값이 최소인 사람을 찾고, 그 사람을 대표로 임명하여 결과 배열에 삽입
// 마지막으로 결과 배열을 정렬하여 크기와 내용 출력