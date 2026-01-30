// Call for Problems
// https://www.acmicpc.net/problem/32498

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int res = 0;
	for (int i = 0; i < n; i++) {
		int p;
		cin >> p;
		if (p % 2 == 1) {
			res++;
		}
	}
	cout << res << '\n';
}

// 주어진 정수들 중 홀수의 개수 구하기