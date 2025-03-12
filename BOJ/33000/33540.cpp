// Helping Out
// https://www.acmicpc.net/problem/33540

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
	map<string, int> m;
	vector<string> v;
	for (int i = 0; i < n; i++) {
		string s;
		int p;
		cin >> s >> p;
		m[s] += p;
		v.push_back(s);
	}
	sort(v.begin(), v.end());
	cout << v[0] << ' ' << m[v[0]] << '\n';
	for (int i = 1; i < n; i++) {
		if (v[i] != v[i - 1]) {
			cout << v[i] << ' ' << m[v[i]] << '\n';
		}
	}
}

// 이름과 점수들이 주어질 때, 이름 별로 합산한 결과 출력하기