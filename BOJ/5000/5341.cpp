// Pyramids
// https://www.acmicpc.net/problem/5341

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	while (true) {
		int n;
		cin >> n;
		if (n == 0) {
			break;
		}
		cout << (n * (n + 1) / 2) << '\n';
	}
}

// 1부터 n까지의 합 구하기

// 이걸 왜 지금까지 안 풀고 있었지