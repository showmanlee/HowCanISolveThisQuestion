// Record Keeping
// https://www.acmicpc.net/problem/9872

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	map<string, int> cnt;
	vector<string> v(3);
	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> v[j];
		}
		sort(v.begin(), v.end());
		string key = v[0] + ' ' + v[1] + ' ' + v[2];
		cnt[key]++;
		res = max(res, cnt[key]);
	}
	cout << res << '\n';
}

// 3마리 쌍들이 주어질 때, 같은 3마리 쌍이 가장 많이 들어온 경우 구하기