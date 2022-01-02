// 문자열 압축 해제
// https://www.acmicpc.net/problem/23746

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
	vector<string> comp(26);
	for (int i = 0; i < n; i++) {
		string t, l;
		cin >> t >> l;
		comp[l[0] - 'A'] = t;
	}
	string before, after;
	cin >> before;
	for (char c : before) {
		after += comp[c - 'A'];
	}
	int s, e;
	cin >> s >> e;
	for (int i = s - 1; i < e; i++) {
		cout << after[i];
	}
	cout << '\n';
}

// 주어진 소문자 문자열을 대문자 하나로 압축하는 쌍이 주어질 때, 주어진 대문자 문자열을 압축 해제한 문자열의 s~e번째 문자 출력하기

// 한 글자당 압축되는 소문자 문자열의 길이는 1000, 그게 1000개까지 주어질 수 있음
// 따라서 모두 압축해제한 후 그 부분만 추출해도 괜찮음
// 그렇게 한다고 하면 각 대문자에 대응하는 문자열을 배열로 저장한 후, 대문자 문자열을 받아 순회하면서 해당 문자에 대응하는 소문자 문자열을 이어붙여서 출력하면 됨