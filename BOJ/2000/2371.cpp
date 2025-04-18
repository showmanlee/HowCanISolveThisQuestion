// 파일 구별하기
// https://www.acmicpc.net/problem/2371

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<vector<int>> v(n);
	for (int i = 0; i < n; i++) {
		int p;
		while (true) {
			cin >> p;
			if (p == -1) {
				break;
			}
			v[i].push_back(p);
		}
	}
	int res = 0;
	for (int i = 0; ; i++) {
		map<int, int> m;
		bool pass = true;
		for (int j = 0; j < n; j++) {
			if (v[j].size() > i) {
				m[v[j][i]]++;
				if (m[v[j][i]] > 1) {
					pass = false;
					break;
				}
			}
		}
		if (pass) {
			res = i + 1;
			break;
		}
	}
	cout << res << '\n';
}

// 주어진 수열들을 처음부터 비교할 때 모두 구분할 수 있는 최소 길이 출력하기