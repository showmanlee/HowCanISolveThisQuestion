// 반올림
// https://www.acmicpc.net/problem/2033

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int p = 10;
	while(n >= p) {
		int t = n % p;
		n /= p;
		if (t >= p / 2) {
			n++;
		}
		n *= p;
		p *= 10;
	}
	cout << n << '\n';
}

// 주어진 수를 가능할 때까지 반올림하기

// 천천히 하면 되는데... 