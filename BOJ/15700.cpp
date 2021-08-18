// 타일 채우기 4
// https://www.acmicpc.net/problem/15700

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	long long a, b;
	cin >> a >> b;
	long long res = a * b;
	res /= 2;
	cout << res << '\n';
}

// n*m 보드에서 1*2 타일을 몇 개나 채울 수 있는가?
// n * m / 2(나머지 버림)