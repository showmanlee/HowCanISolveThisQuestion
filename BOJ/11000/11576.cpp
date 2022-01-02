// Base Conversion
// https://www.acmicpc.net/problem/11576

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a, b, n;
	cin >> a >> b >> n;
	long long p = 0, t = 1;
	for (int i = 1; i < n; i++)
		t *= a;
	for (int i = 0; i < n; i++) {
		long long d;
		cin >> d;
		p += d * t;
		t /= a;
	}
	vector<long long> res;
	while (p != 0) {
		res.push_back(p % b);
		p /= b;
	}
	reverse(res.begin(), res.end());
	for (long long i : res)
		cout << i << ' ';
	cout << '\n';
}

// a진수를 b진수로 전환하기

// 먼저 a진수를 받으며 해당 수를 정수형으로 저장하기 - 숫자에 초기값이 a^(n - 1)인 지수를 곱해서 더하고, 지수를 a로 나누기
// 이후 이진수 만들듯이 만들어진 정수를 b진수로 풀어내기