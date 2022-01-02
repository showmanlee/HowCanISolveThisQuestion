// 프린터 큐
// https://www.acmicpc.net/problem/1966

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(void) {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		queue<int> q;
		int n, m, count = 0;
		cin >> n >> m;
		vector<int> prior(n);
		for (int i = 0; i < n; i++) {
			q.push(i);
			cin >> prior[i];
		}
		while (!q.empty()) {
			int p = q.front();
			q.pop();
			bool fail = false;
			for (int i = 0; i < n; i++)
				if (prior[i] > prior[p]) {
					q.push(p);
					fail = true;
					break;
				}
			if (!fail) {
				count++;
				prior[p] = -1;
				if (p == m)
					break;
			}
		}
		cout << count << '\n';
	}
}