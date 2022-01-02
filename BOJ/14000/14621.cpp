// 나만 안 되는 연애
// https://www.acmicpc.net/problem/14621

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;
typedef pair<int, pr> prr;
int group[1001];

int finding(int p) {
	if (p == group[p])
		return p;
	group[p] = finding(group[p]);
	return group[p];
}

void unioning(int a, int b) {
	int pa = finding(a);
	int pb = finding(b);
	if (pa > pb)
		group[pa] = pb;
	else if (pb > pa)
		group[pb] = pa;

}
int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<char> school(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> school[i];
		group[i] = i;
	}
	vector<prr> edges(m);
	for (int i = 0; i < m; i++)
		cin >> edges[i].second.first >> edges[i].second.second >> edges[i].first;
	sort(edges.begin(), edges.end());
	int cnt = 0;
	int res = 0;
	for (int i = 0; i < m; i++) {
		int cost = edges[i].first;
		int a = edges[i].second.first;
		int b = edges[i].second.second;
		if (school[a] == school[b])
			continue;
		if (finding(a) != finding(b)) {
			unioning(a, b);
			cnt++;
			res += cost;
		}
		if (cnt == n - 1)
			break;
	}
	if (cnt != n - 1)
		res = -1;
	cout << res << '\n';
}

// 대학교들의 남초/여초 여부, 대학교 사이를 잇는 도로들과 그 길이가 주어졌을 때, 남초대와 여초대 사이를 잇는 도로로만 구성된 MST의 길이 출력하기

// 기본적인 MST 문제 - 여기에 남초/여초 여부를 따져야 함
// 간선 정렬 후 크루스칼을 돌리면서, 같은 성별의 대학끼리 연결된 간선인 경우 버리도록 처리
// 그 외에는 기본적으로 양방향 그래프에 대한 크루스칼과 똑같이 그려주고, 간선의 합을 구하면 됨
// 그러나 만약 쌓인 간선이 n - 1보다 적다면 -1 출력