// Total Circle
// https://www.acmicpc.net/problem/17093

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<long long, long long> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<pr> p(n), q(m);
	for (int i = 0; i < n; i++) {
		cin >> p[i].first >> p[i].second;
	}
	for (int i = 0; i < m; i++) {
		cin >> q[i].first >> q[i].second;
	}
	long long res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			long long x = p[i].first - q[j].first;
			long long y = p[i].second - q[j].second;
			res = max(res, x * x + y * y);
		}
	}
	cout << res << '\n';
}

// p의 모든 점을 포함하고 q 점 중 하나를 중심으로 갖는 최소 원의 최대 반지름 구하기