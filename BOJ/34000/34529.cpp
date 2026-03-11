// Acquiring SW-IT Corn
// https://www.acmicpc.net/problem/34529

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	long long x, y, z, u, v, w;
	cin >> x >> y >> z >> u >> v >> w;
	long long res = (x * u / 100) + (y * v / 50) + (z * w / 20);
	cout << res << '\n';
}

// 주어진 대로 총 가격 구하기