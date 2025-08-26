// 다각형그리기
// https://www.acmicpc.net/problem/2641

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> key(n);
	for (int i = 0; i < n; i++) {
		cin >> key[i];
	}
	int m;
	cin >> m;
	vector<vector<int>> res;
	for (int t = 0; t < m; t++) {
		vector<int> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		bool pass = false;
		for (int i = 0; i < n; i++) {
			bool passs = true;
			for (int j = 0; j < n; j++) {
				if (v[j] != key[(j + i) % n]) {
					passs = false;
					break;
				}
			}
			if (passs) {
				pass = true;
			}
		}
		if (!pass) {
			vector<int> vv(n);
			for (int i = 0; i < n; i++) {
				vv[i] = (v[i] % 2 == 1 ? (v[i] == 1 ? 3 : 1) : (v[i] == 2 ? 4 : 2));
			}
			reverse(vv.begin(), vv.end());
			for (int i = 0; i < n; i++) {
				bool passs = true;
				for (int j = 0; j < n; j++) {
					if (vv[j] != key[(j + i) % n]) {
						passs = false;
						break;
					}
				}
				if (passs) {
					pass = true;
				}
			}
		}
		if (pass) {
			res.push_back(v);
		}
	}
	cout << res.size() << '\n';
	for (auto& v : res) {
		for (int i : v) {
			cout << i << ' ';
		}
		cout << '\n';
	}
}

// 주어진 좌표 이동 경로와 같은 모양을 그리게 되는 경로 출력하기