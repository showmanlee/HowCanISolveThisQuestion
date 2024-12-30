// 흑백 요리사
// https://www.acmicpc.net/problem/32653

#include <iostream>
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

long long lcm(long long a, long long b) {
	return a * b / gcd(a, b);
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    long long res = 1;
    for (int i = 0; i < n; i++) {
        long long p;
        cin >> p;
        p *= 2;
        res = lcm(res, p);
    }
    cout << res << '\n';
}

// 스테이크의 한 면을 최소한으로 익하는데 걸리는 시간이 주어질 때, 모든 스테이크의 양면을 동시에 같은 시간만큼 굽는 최소 시간 구하기