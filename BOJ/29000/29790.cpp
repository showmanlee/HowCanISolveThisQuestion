// 임스의 메이플컵
// https://www.acmicpc.net/problem/29790

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	int n, u, l;
	cin >> n >> u >> l;
	int res = 0;
	if (n >= 1000) {
		res++;
		if (u >= 8000 || l >= 260) {
			res++;
		}
	}
	cout << (res >= 1 ? (res == 2 ? "Very Good" : "Good") : "Bad") << '\n';
}

// n >= 1000일 경우 Good, Good이면서 u >= 8000이거나 l >= 260일 경우 Very Good, 그렇지 않다면 Bad 출력하기

// 조건 확인하며 출력하기