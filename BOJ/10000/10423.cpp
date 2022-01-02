// 전기가 부족해
// https://www.acmicpc.net/problem/10423

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
	
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		group[i] = i;
	int cnt = 0;
	int power;
	cin >> power;
	for (int i = 1; i < k; i++) {
		int p;
		cin >> p;
		unioning(p, power);
		cnt++;
	}
	vector<prr> cables(m);
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		cables[i] = { w, {u, v} };
	}
	sort(cables.begin(), cables.end());
	int res = 0;
	for (prr& e : cables) {
		int cost = e.first;
		int x = e.second.first;
		int y = e.second.second;
		if (finding(x) != finding(y)) {
			unioning(x, y);
			cnt++;
			res += cost;
		}
		if (cnt == n - 1)
			break;
	}
	cout << res << '\n';
}

// 설치 비용이 다른 m개의 케이블로 연결된 n개의 도시 중 k개가 발전소일 때, 모든 도시에 전기를 공급할 수 있게 하는 최소 비용은?

// 기본적으로 MST 문제 - 그런데 특정 노드들과 연결되어 있어야 함
// 어쨌든 MST를 만드는 과정에서 모든 노드는 서로 연결됨 - 따라서 모든 도시는 필연적으로 발전소와 연결됨
// 하지만 발전소가 여러 개이므로 단순히 MST를 돌리게 되면 중복해서 연결되는 경우가 생길 수 있음
// 발전소들을 가중치 0인 간선으로 모두 연결한다고 생각하고 시작하면 이러한 문제를 막을 수 있음 - 발전소를 잇는 가상 간선 역시 MST 필요 간선 수에 포함됨

// 우선 발전소들을 받은 후 해당 발전소들을 차례대로 union 처리한다
// 이후 케이블들을 받고 가중치로 정렬한 후, 일반적인 크루스칼처럼 MST를 만들며 가중치들을 모두 더해간다
// 이렇게 가상 간선 포함 n - 1개의 케이블이 사용되면 생성 과정을 마무리하고 결과 출력하기