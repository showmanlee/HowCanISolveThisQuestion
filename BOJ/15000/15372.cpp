// A Simple Problem.
// https://www.acmicpc.net/problem/15372

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		long long n;
		cin >> n;
		cout << (n * n) << '\n';
	}
}

// n이 주어질 때, n의 제곱의 배수가 되게 하는 k의 최솟값 구하기

// n의 제곱을 구하라는 말 - long long으로 입력해야 함에 주의