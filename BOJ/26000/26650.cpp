// 그램팬
// https://www.acmicpc.net/problem/26650

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<char, long long> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	cin >> s;
	vector<pr> v;
	char cur = s[0];
	int cnt = 1;
	for (int i = 1; i < s.length(); i++) {
		if (s[i] == cur) {
			cnt++;
		} else {
			v.push_back({cur, cnt});
			cnt = 1;
			cur = s[i];
		}
	}
	v.push_back({cur, cnt});
	
	long long res = 0;
	if (v.size() >= 26) {
		for (int i = 0; i <= v.size() - 26; i++) {
			bool pass = true;
			for (int j = 0; j < 26; j++) {
				if (v[i + j].first != 'A' + j) {
					pass = false;
					break;
				}
			}
			if (pass) {
				res += v[i].second * v[i + 25].second;
			}
		}
	}
	cout << res << '\n';
}

// 주어진 대문자 문자열에서 A부터 Z까지 순서대로 등장하는 부분 문자열의 개수 출력하기