// いずれか片方 (Either, but Not Both)
// https://www.acmicpc.net/problem/33171

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, a, b;
	cin >> n >> a >> b;
	int res = 0;
	for (int i = 1; i <= n; i++) {
		if ((i % a == 0) ^ (i % b == 0)) {
			res++;
		}
	}
	cout << res << '\n';
}

// n개의 자연수에 대한 최소공배수 구하기