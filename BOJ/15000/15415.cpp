// Shattered Cake
// https://www.acmicpc.net/problem/15415

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	long long w;
	int n;
	cin >> w >> n;
	long long res = 0;
	for (int i = 0; i < n; i++) {
		long long a, b;
		cin >> a >> b;
		res += a * b;
	}
	res /= w;
	cout << res << '\n';
}

// 한 변의 길이가 w였던 케이크가 주어진 크기들의 n개의 조각으로 나뉘었을 떄, 전체 케이크의 다른 변의 길이 구하기