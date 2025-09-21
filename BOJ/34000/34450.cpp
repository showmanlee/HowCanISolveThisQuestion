// Partial Transmission
// https://www.acmicpc.net/problem/34450

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, p;
	cin >> n >> p;
	vector<bool> v(n);
	for (int i = 1; i < n; i++) {
		int t;
		cin >> t;
		v[t - p] = true;
	}
	for (int i = 0; i < n; i++) {
		if (!v[i]) {
			cout << (i + p) << '\n';
			break;
		}
	}
}

// p~n+p-1까지의 수 중 빠진 수 출력하기