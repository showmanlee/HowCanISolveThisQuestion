// 그거 왜 말해!
// https://www.acmicpc.net/problem/33985

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	string s;
	cin >> n >> s;
	if (s[0] == 'B' || s[n - 1] == 'A') {
		cout << "No\n";
	} else {
		cout << "Yes\n";
	}
}

// 2015년 1월 16일부터 주어진 날짜까지 몇 개의 계절을 함께했는지 구하기