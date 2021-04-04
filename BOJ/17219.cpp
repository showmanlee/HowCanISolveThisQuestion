// 비밀번호 찾기
// https://www.acmicpc.net/problem/17219

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	unordered_map<string, string> sites;
	for (int i = 0; i < n; i++) {
		string s, p;
		cin >> s >> p;
		sites[s] = p;
	}
	for (int i = 0; i < m; i++) {
		string q;
		cin >> q;
		cout << sites[q] << '\n';
	}
}

// 사이트에 맞는 비밀번호 불러오기
// 대놓고 해시를 쓰라고 만든 문제
// map은 Red-Black Tree 기반, unordered_map(hash_map)은 해시 테이블 기반
// unordered_map은 insert보다 s[n]처럼 쓰는 게 편하더라