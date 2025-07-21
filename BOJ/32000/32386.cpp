// KCPC에 등장할 알고리즘 맞히기
// https://www.acmicpc.net/problem/32386

#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int n;
	cin >> n;
	map<string, int> dict;
	vector<string> v;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		for (int j = 0; j < b; j++) {
			string s;
			cin >> s;
			dict[s]++;
			if (dict[s] == 1) {
				v.push_back(s);
			}
		}
	}
	int maxx = 0, cnt = 0;
	string maxs;
	for (string s : v) {
		if (dict[s] > maxx) {
			maxx = dict[s];
			maxs = s;
			cnt = 1;
		} else if (dict[s] == maxx) {
			cnt++;
		}
	}
	if (cnt > 1) {
		cout << -1 << '\n';
	} else {
		cout << maxs << '\n';
	}
}

// 주어진 속성들 중 가장 많이 나오면서 유일한 속성 구하기