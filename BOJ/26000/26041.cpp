// 비슷한 전화번호 표시
// https://www.acmicpc.net/problem/26041

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<string> v;
	string s;
	while (cin >> s) {
		v.push_back(s);
	}
	string key = v[v.size() - 1];
	int res = 0;
	for (int i = 0; i < v.size() - 1; i++) {
		if (v[i].length() > key.length() && v[i].substr(0, key.length()) == key) {
			res++;
		}
	}
	cout << res << '\n';
}

// 문자열들이 주어질 때, 기준 문자열과 같지 않으며 기준 문자열을 접두사로 가지는 문자열의 개수 구하기

// 문자열들에 대해 기준 문자열보다 길고 첫 문자부터 기준 문자열 길이까지의 부분 문자열이 기준 문자열과 같으면 카운트 증가