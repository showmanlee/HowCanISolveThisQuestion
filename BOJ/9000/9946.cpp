// 단어 퍼즐
// https://www.acmicpc.net/problem/9946

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int tt = 1;
	while (true) {
		string s, t;
		cin >> s >> t;
		if (s == "END" && t == "END") {
			break;
		}
		vector<int> a(26), b(26);
		for (char c : s) {
			a[c - 'a']++;
		}
		for (char c : t) {
			b[c - 'a']++;
		}
		bool res = true;
		for (int i = 0; i < 26; i++) {
			if (a[i] != b[i]) {
				res = false;
				break;
			}
		}
		cout << "Case " << tt << ": " << (res ? "same" : "different") << '\n';
		tt++;
	}
}

// 두 문자열에 사용된 알파벳 종류가 동일한지 판정하기

// 두 개의 26칸 배열을 만들어 문자열의 알파벳 개수를 센 뒤 판정한다