// 주차장
// https://www.acmicpc.net/problem/5464

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<int> price(n);
	vector<int> active(n);
	vector<int> weight(m + 1);
	for (int i = 0; i < n; i++) {
		cin >> price[i];
	}
	for (int j = 1; j <= m; j++) {
		cin >> weight[j];
	}
	queue<int> q;
	int aCnt = n;
	long long res = 0;
	for (int t = 0; t < 2 * m; t++) {
		int p;
		cin >> p;
		if (p > 0) {
			if (aCnt == 0) {
				q.push(p);
			} else {
				for (int i = 0; i < n; i++) {
					if (active[i] == 0) {
						active[i] = p;
						aCnt--;
						break;
					}
				}
			}
		} else {
			p = -p;
			int pos = 0;
			for (int i = 0; i < n; i++) {
				if (active[i] == p) {
					active[i] = 0;
					res += price[i] * weight[p];
					aCnt++;
					pos = i;
					break;
				}
			}
			if (aCnt == 1 && !q.empty()) {
				int pp = q.front();
				q.pop();
				active[pos] = pp;
				aCnt--;
			}		
		}
	}
	cout << res << '\n';
}

// 문제에서 주어진 대로 주차장 출입 기록과 요금이 주어질 떄, 총 수익 출력하기