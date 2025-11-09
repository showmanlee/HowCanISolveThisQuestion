// Quick Estimates
// https://www.acmicpc.net/problem/13297

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		cout << s.length() << '\n';
	}
}

// 주어진 수의 길이 출력하기