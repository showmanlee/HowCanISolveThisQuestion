// 전주 듣고 노래 맞히기
// https://www.acmicpc.net/problem/31562

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	map<string, string> dict;
	for (int i = 0; i < n; i++) {
		int t;
		string s;
		cin >> t >> s;
		string k;
		for (int j = 0; j < 7; j++) {
			char c;
			cin >> c;
			if (j < 3) {
				k += c;
			}
		}
		if (dict[k] == "") {
			dict[k] = s;
		} else {
			dict[k] = "?";
		}
	}
	for (int i = 0; i < m; i++) {
		string s;
		for (int j = 0; j < 3; j++) {
			char c;
			cin >> c;
			s += c;
		}
		cout << (dict[s] == "" ? "!" : dict[s]) << '\n';
	}
}

// 노래 제목과 첫 7음계가 주어질 때, 첫 3음계로 노래 찾기