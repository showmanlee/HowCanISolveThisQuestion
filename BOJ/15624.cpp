// 피보나치 수 7
// https://www.acmicpc.net/problem/15624

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	vector<long long> fib(n + 1);
	fib[0] = 0;
	fib[1] = 1;
	for (int i = 2; i <= n; i++)
		fib[i] = (fib[i - 1] + fib[i - 2]) % 1000000007;
	cout << fib[n] << '\n';
}

// 100만까지의 피보나치 수의 % 1000000007 구하기
// long long 배열에서 저장하기