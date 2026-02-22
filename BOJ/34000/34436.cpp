// Alliteration
// https://www.acmicpc.net/problem/34436

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++) {
		vector<int> cnt(26);
		int maxx = 0;
		char res = 'z';
		string s, t;
		getline(cin, s);
		stringstream ss(s);
		while (ss >> t) {
			int idx = t[0] - 'a';
			cnt[idx]++;
			if (cnt[idx] > maxx) {
				maxx = cnt[idx];
				res = t[0];
			} else if (cnt[idx] == maxx) {
				res = min(res, t[0]);
			}
		}
		cout << res << '\n';
	}
}

// 한 줄에 주어진 단어들 중 가장 많이 나온 단어의 첫 글자 출력하기