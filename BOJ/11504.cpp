// 돌려 돌려 돌림판!
// https://www.acmicpc.net/problem/11504

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void) {
	int tc;
	cin >> tc;
	for (int t = 0; t < tc; t++) {
		int n, m, x = 0, y = 0, answer = 0;
		cin >> n >> m;
		string xx, yy;
		vector<string> v(n);
		for (int i = 0; i < m; i++) {
			string p;
			cin >> p;
			xx += p;
		}
		for (int i = 0; i < m; i++) {
			string p;
			cin >> p;
			yy += p;
		}
		for (int i = 0; i < n; i++)
			cin >> v[i];
		x = stoi(xx);
		y = stoi(yy);

		for (int i = 0; i < n; i++) {
			string pp;
			for (int j = 0; j < m; j++)
				pp += v[(i + j) % n];
			int p = stoi(pp);
			if (x <= p && p <= y)
				answer++;
		}

		cout << answer << endl;
	}
}