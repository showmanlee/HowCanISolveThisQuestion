// Archivist
// https://www.acmicpc.net/problem/20232

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<string> v = {
		"ITMO",
		"SPbSU",
		"SPbSU",
		"ITMO",
		"ITMO",
		"SPbSU",
		"ITMO",
		"ITMO",
		"ITMO",
		"ITMO",
		"ITMO",
		"PetrSU, ITMO",
		"SPbSU",
		"SPbSU",
		"ITMO",
		"ITMO",
		"ITMO",
		"ITMO",
		"SPbSU",
		"ITMO",
		"ITMO",
		"ITMO",
		"ITMO",
		"SPbSU",
		"ITMO"
	};
	int n;
	cin >> n;
	n -= 1995;
	cout << v[n] << '\n';
}

// 연도가 주어질 때, 해당 연도의 수상자 출력하기

// 수상자 목록은 문제에 있습니다 - 참고하고 출력합시다