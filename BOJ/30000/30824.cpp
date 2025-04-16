// 피보나치 더하기
// https://www.acmicpc.net/problem/30824

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<long long> fib(79);
	fib[0] = 0; 
	fib[1] = 1;
	for (int i = 2; i <= 78; i++) {
		fib[i] = fib[i - 1] + fib[i - 2];
	}

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		int k;
		long long n;
		cin >> k >> n;
		bool res = false;
		if (k == 1) {
			for (int i = 1; i <= 78; i++) {
				if (fib[i] == n) {
					res = true;
				}
			}
		} else if (k == 2) {
			for (int i = 1; i <= 78; i++) {
				for (int j = i; j <= 78; j++) {
					if (fib[i] + fib[j] == n) {
						res = true;
					}
				}
			}
		} else if (k == 3) {
			for (int i = 1; i <= 78; i++) {
				for (int j = i; j <= 78; j++) { 
					for (int l = j; l <= 78; l++) {
						if (fib[i] + fib[j] + fib[l] == n) {
							res = true;
						}
					}
				}
			}
		}
		cout << (res ? "YES" : "NO") << '\n';
	}
}

// 피보나치 수열의 원소 k개의 합으로 n을 만들 수 있는지 구하기