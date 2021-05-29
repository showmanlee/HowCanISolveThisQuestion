// 치킨 배달
// https://www.acmicpc.net/problem/15686

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
typedef pair<int, int> pr;

int n, m;
pr houses[101], chickens[14];
bool checker[14];
int hc, cc;
int res;

void dfs(int p, int cnt) {
	checker[p] = true;
	if (cnt == m) {
		int ret = 0;
		for (int i = 0; i < hc; i++) {
			int dist = 987654321;
			for (int j = 0; j < cc; j++) {
				if (checker[j])
					dist = min(dist, abs(houses[i].first - chickens[j].first) + abs(houses[i].second - chickens[j].second));
			}
			ret += dist;
		}
		res = min(res, ret);
	}
	else {
		for (int i = p + 1; i < cc; i++)
			dfs(i, cnt + 1);
	}
	checker[p] = false;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	hc = cc = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int p;
			cin >> p;
			if (p == 1) {
				houses[hc] = { i, j };
				hc++;
			}
			else if (p == 2) {
				chickens[cc] = { i, j };
				cc++;
			}
		}
	}
	res = 987654321;
	for (int i = 0; i < cc; i++)
		dfs(i, 1);
	cout << res << '\n';
}

// n*n 도시에 집들과 치킨집이 있고, 그 중 최대 m개의 치킨집만을 남겨 각 집과 가장 가까운 치킨집의 맨해튼 거리(치킨 거리)를 최소로 만든 결과는?

// *최대* m개를 고르라고 하긴 했지만, '가까운 치킨집'의 수를 늘리기 위해서는 치킨집을 최대한 많이 놓는 것이 이득이기에 그냥 m개를 골라도 됨
// 고르는 과정은 dfs 백트래킹을 활용하기 - 이를 위해 집들의 좌표와 치킨집들의 좌표를 별도의 배열로 정리해두기
// 선택한 이후에는 각 집과 선택한 치킨집들의 거리의 최소의 합을 구하며 결과값을 갱신