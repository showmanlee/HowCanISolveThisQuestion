// JOI ソート (JOI Sort)
// https://www.acmicpc.net/problem/20977

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> v(26);
	for (int i = 0; i < n; i++) {
		char c;
		cin >> c;
		v[c - 'A']++;
	}
	for (int i = 0; i < v['J' - 'A']; i++) {
		cout << "J";
	}
	for (int i = 0; i < v['O' - 'A']; i++) {
		cout << "O";
	}
	for (int i = 0; i < v['I' - 'A']; i++) {
		cout << "I";
	}
	cout << '\n';
}

// J, O, I로 구성된 문자열의 문자들을 J, O, I 순으로 정렬하기

// 하면 됩니다 - 알파벳 순서가 아니니 직접 세서 그만큼 출력하는 방식으로...