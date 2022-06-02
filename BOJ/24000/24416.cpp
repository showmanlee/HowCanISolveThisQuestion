// 알고리즘 수업 - 피보나치 수 1
// https://www.acmicpc.net/problem/24416

#include <iostream>
#include <algorithm>
using namespace std;

int a = 0;
int b = 0;
int f[41];

int fib(int n) {
    if (n == 1 || n == 2) {
		a++;
		return 1;
	}
    return (fib(n - 1) + fib(n - 2));
}

int fibonacci(int n) {
    f[1] = f[2] = 1;
    for (int i = 3; i <= n; i++) {
		b++;
		f[i] = f[i - 1] + f[i - 2];
	}
    return f[n];
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	fib(n);
	fibonacci(n);
	cout << a << ' ' << b << '\n';
}

// 피보나치 수를 재귀와 dp로 풀 때 최종 코드 접근 횟수 구하기

// 수가 적으므로 직접 구해볼 수 있음 - 다만 이것보다 길어지면 가상으로 구해봐야겠지