// 비슷한 단어
// https://www.acmicpc.net/problem/1411

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<string> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		vector<int> visit(26);
		int cnt = 0;
		string s;
		for (char c : v[i]) {
			if (visit[c - 'a'] == 0) {
				cnt++;
				visit[c - 'a'] = cnt;
			}
			s += (char)('a' - 1 + visit[c - 'a']);
		}
		v[i] = s;
	}
	int res = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (v[i] == v[j]) {
				res++;
			}
		}
	}
	cout << res << '\n';
}

// 주어진 소문자 문자열들 중 2개를 골라 문자열 하나의 알파벳들을 다른 고유한 알파벳으로 바꿔 같아지는 쌍 개수는?

// 알파벳 나열 상태가 같은 쌍을 찾는 것 - 다시 말해 알파벳을 등장한 순서대로 숫자를 매겼을 때 같은 경우가 나오는 수란 것
// 이를 이용해 등장하는 알파벳에 배치에 따른 문자열로 변환하고, 이후 모든 쌍에 대해 같은 경우의 수를 발견하면 ++