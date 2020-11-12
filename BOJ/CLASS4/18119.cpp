// 단어 암기
// https://www.acmicpc.net/problem/18119

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int main(void) {
	int n, m;
	cin >> n >> m;
	vector<string> str(n);
	vector<int> mask(n);
	int mem = 0b11111111111111111111111111;
	for (int i = 0; i < n; i++) {
		cin >> str[i];
		for (char c : str[i])
			mask[i] |= 1 << (c - 'a');
	}
	for (int i = 0; i < m; i++) {
		int t;
		char c;
		cin >> t >> c;
		if (t == 2)
			mem |= 1 << (c - 'a');
		else
			mem &= ~(1 << (c - 'a'));
		int res = 0;
		for (int p : mask) {
			if ((mem & p) == p)
				res++;
		}
		cout << res << '\n';
	}
}

// 비트마스킹 - 배열 대신 이진수로 기억해서 메모리를 절약하자
// 이왕이면 단어 메모리 역시 비트로 저장하자 - 그리고 알파벳 별로 비트 저장하면 문자 순회없이 비트 연산 한번 하면 결과 나올 것
// 1로 만들기 - 비트 | 1 << 자릿수
// 0으로 만들기 - 비트 & ~(1 << 자릿수)