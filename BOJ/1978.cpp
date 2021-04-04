// 소수 찾기
// https://www.acmicpc.net/problem/1978

#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n) {
	if (n == 1)
		return false;
	for (int i = 2; i <= sqrt(n); i++)
		if (n % i == 0)
			return false;
	return true;
}

int main(void) {
	int n, count = 0;;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (isPrime(a))
			count++;
	}
	cout << count << '\n';
}

// 소수는 sqrt(n)까지만 구하면 되더라