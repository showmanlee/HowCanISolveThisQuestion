// Eye of Sauron
// https://www.acmicpc.net/problem/24405

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	cin >> s;
	int l = 0, r = 0;
	int* cur = &l;
	for (char c : s) {
		if (c == '|') {
			(*cur)++;
		} else if (c == '(') {
			cur = &r;
		}
	}
	cout << (l == r ? "correct" : "fix") << '\n';
}

// () 좌우에 있는 |의 개수가 서로 동일한지 구하기