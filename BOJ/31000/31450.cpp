// Everyone is a winner
// https://www.acmicpc.net/problem/31450

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int m, k;
	cin >> m >> k;
	cout << (m % k == 0 ? "Yes" : "No") << '\n';
}

// m이 k로 나누어떨어지는지 구하기