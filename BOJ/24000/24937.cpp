// SciComLove (2022)
// https://www.acmicpc.net/problem/24937

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s = "SciComLove";
	int n;
	cin >> n;
	for (int i = 0; i < 10; i++) {
		cout << s[(i + n) % 10];
	}
	cout << '\n';
}

// 문자열 SciComLove를 n만큼 좌측으로 순환시키기

// 흔한 문자열 순환 문제