// 최대공약수
// https://www.acmicpc.net/problem/1850

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

long long gcd(long long a, long long b) {
	if (a < b)
		swap(a, b);
	while (b != 0) {
		long long n = a % b;
		if (n == 0)
			return b;
		else {
			a = b;
			b = n;
		}
	}
	return 1;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	long long a, b;
	cin >> a >> b;
	long long res = gcd(a, b);
	string s;
	for (long long i = 0; i < res; i++) {
		s += '1';
	}
	cout << s << '\n';
}

// a, b자리의 1로 구성된 수의 최대공약수 구하기

// 당연히 a, b자리를 1로 구성된 수로 바꿔서 구하는 문제는 아니고, 규칙이 있음
// 1은 모든 수의 공약수가 될 수 있음
// 11은 11, 1111, 111111... 등 2의 배수 자리의 공약수가 될 수 있고(1, 101, 10001배...), 같은 원리로 111은 3의 배수 자리, 1111은 4의 배수 자리의 공약수가 될 수 있음
// 따라서 자릿수의 최대공약수 자리의 수가 그들의 최대공약수가 된다고 볼 수 있음 - 실제로 그렇고