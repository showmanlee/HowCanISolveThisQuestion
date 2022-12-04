// WARBOY
// https://www.acmicpc.net/problem/26082

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a, b, c;
	cin >> a >> b >> c;
	cout << (b / a * c * 3) << '\n';
}

// a, b, c가 주어질 때, b / a * c * 3 구하기

// 구해보세요