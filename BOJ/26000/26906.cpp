// Vikingahackare
// https://www.acmicpc.net/problem/26906

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	map<string, string> v;
	for (int i = 0; i < n; i++) {
		string a, b;
		cin >> a >> b;
		v[b] = a;
	}
	string s;
	cin >> s;
	string res;
	for (int i = 0; i < s.length(); i += 4) {
		string ss = s.substr(i, 4);
		if (v[ss] == "") {
			res += '?';
		} else {
			res += v[ss];
		}
	}
	cout << res << '\n';
}

// 2진수 코드와 해독표가 주어질 때, 해독하기