// 사이클 단어
// https://www.acmicpc.net/problem/1544

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<string> s(n);
	vector<int> id(n);
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	int idx = 0;
	for (int i = 0; i < n; i++) {
		if (id[i] == 0) {
			idx++;
 			id[i] = idx;
		} else {
			continue;
		}
		for (int j = i + 1; j < n; j++) {
			if (s[i].length() != s[j].length() || id[j] != 0) {
				continue;
			}
			string ss = s[i];
			for (int t = 0; t < s[i].length(); t++) {
				if (ss == s[j]) {
					id[j] = id[i];
					break;
				}
				ss = ss.substr(1) + ss[0];
			}
		}
	}
	cout << idx << '\n';
}

// 주어진 문자열들 중 원형으로 썼을 때 서로 같은 문자열을 제외한 서로 다른 문자열이 몇 개인지 구하기

// 문자열들을 순회하며, '새로운 문자열'을 발견했을 때 해당 문자열과 나머지 문자열을 비교해본다
// 브루트포스로 가능하긴 하나, 중복 탐색 케이스를 줄여 시간을 절약할 수 있음