// SUAPC 2024 Winter
// https://www.acmicpc.net/problem/32154

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<string> v = {
		"ABCDEFGHJLM",
		"ACEFGHILM",
		"ACEFGHILM",
		"ABCEFGHLM",
		"ACEFGHLM",
		"ACEFGHLM",
		"ACEFGHLM",
		"ACEFGHLM",
		"ACEFGHLM",
		"ABCFGHLM"
	};
	int n;
	cin >> n;
	n--;
	cout << v[n].length() << '\n';
	for (char c : v[n]) {
		cout << c << ' ';
	}
	cout << '\n';
}

// 주어진 문제에서 n등이 푼 문제 구하기