// Q
// https://www.acmicpc.net/problem/4540

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		int n, m;
		cin >> n >> m;
		vector<string> v(n + 1), res(n + 1);
		vector<bool> visit(n + 1);
		for (int i = 1; i <= n; i++) {
			cin >> v[i];
		}
		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			res[b] = v[a];
			visit[a] = true;
		}
		int idx = 1;
		for (int i = 1; i <= n; i++) {
			if (res[i].empty()) {
				while (visit[idx]) {
					idx++;
				}
				res[i] = v[idx];
				idx++;
			}
		}
		for (int i = 1; i <= n; i++) {
			cout << res[i] << ' ';
		}
		cout << '\n';
	}
}

// 큐에서 원소 위치를 고정하고 채워넣은 결과 출력하기