// 火曜日 (Tuesday)
// https://www.acmicpc.net/problem/31611

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	cout << (n % 7 == 2) << '\n';
}

// 일요일의 n일 후가 화요일인지 구하기