// 최소공배수
// https://www.acmicpc.net/problem/13241

#include <iostream>
#include <algorithm>
using namespace std;

long long gcd(long long a, long long b) {
	if (a < b)
		swap(b, a);
	while (b > 0) {
		int t = a % b;
		a = b;
		b = t;
	}
	return a;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	long long a, b;
	cin >> a >> b;
	long long res = a * b / gcd(a, b);
	cout << res << '\n';
}

// 어떤 두 수의 최소공배수 구하기

// lcm(a, b) = a * b / gcd(a, b)