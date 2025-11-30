// 문자열 로또
// https://www.acmicpc.net/problem/34803

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int l, n;
	cin >> l >> n;
	vector<string> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	int m;
	cin >> m;
	map<string, bool> visit;
	vector<string> keys;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < l - m + 1; j++) {
			string ss = v[i].substr(j, m);
			if (!visit[ss]) {
				visit[ss] = true;
				keys.push_back(ss);
			}
		}
 	}
	int res = 0;
	for (string s : keys) {
		int p = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < l - m + 1; j++) {
				if (s == v[i].substr(j, m)) {
					p++;
				}
			}		
		}
		res = max(res, p);
	}
	cout << res << '\n';
}

// 주어진 문자열들에서 부분문자열로 가장 많이 뽑아낼 수 있는 길이 m의 문자열 찾기