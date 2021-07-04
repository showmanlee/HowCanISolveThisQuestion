// 학교 탐방하기
// https://www.acmicpc.net/problem/13418

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;
typedef pair<int, pr> prr;

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
	vector<prr> roads(m + 1);
	for (int i = 0; i <= m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		c = (c == 1 ? 0 : 1);
		roads[i] = { c, {a, b} };
	}
	sort(roads.begin(), roads.end(), [](prr a, prr b) {
		return a.first < b.first; });
	for (int i = 0; i <= n; i++)
		group[i] = i;
	int r1 = 0;
	int cnt = 0;
	for (prr& e : roads) {
		int cost = e.first;
		int x = e.second.first;
		int y = e.second.second;
		if (finding(x) != finding(y)) {
			unioning(x, y);
			cnt++;
			r1 += cost;
		}
		if (cnt == n)
			break;
	}
	sort(roads.begin(), roads.end(), [](prr a, prr b) {
		return a.first > b.first; });
	for (int i = 0; i <= n; i++)
		group[i] = i;
	int r2 = 0;
	cnt = 0;
	for (prr& e : roads) {
		int cost = e.first;
		int x = e.second.first;
		int y = e.second.second;
		if (finding(x) != finding(y)) {
			unioning(x, y);
			cnt++;
			r2 += cost;
		}
		if (cnt == n)
			break;
	}
	int res = (r2 * r2) - (r1 * r1);
	cout << res << '\n';
}

// 오르막길과 내리막길로 구성된 학교 건물들을 모두 탐색하기 위해 1번 건물로 들어가는 입구에서 출발하는 경로 중 피로도(오르막길 수 ^ 2)가 가장 큰 경로와 작은 경로의 피로도 차는?

// 문제 잘 읽기 - 출발지는 0번이고, 건물은 1~n이며, 비탈 표시에서 1이 내리막길임에 주의
// 또한 0-1 경로는 m에 포함되지 않음에 주의 - 따라서 실제 지점 수는 n+1(0~n)개, 도로 수는 m+1개가 됨
// 이것에 주의하면 보드 받기 - 편한 계산을 위해 오르막길은 1, 내리막길은 0으로 바꿔서 저장
// 최소 피로도 도로의 경우 경사 여부를 가중치 삼아 MST로 구하면 됨 - MST를 만들면서 만나는 오르막길 개수를 저장
// 반대로 최대 피로도 도로의 경우 간선 우선순위를 반대로 한 '최대 스패닝 트리'를 구하면 됨
// 이렇게 두 스패닝 트리에서 나온 오르막길 수들을 제곱하여 서로 뺀 것이 답