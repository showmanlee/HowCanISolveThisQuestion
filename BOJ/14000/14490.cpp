// 백대열
// https://www.acmicpc.net/problem/14490

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
	if (a < b)
		swap(a, b);
	while (b != 0) {
		int n = a % b;
		if (n == 0)
			return b;
		else {
			a = b;
			b = n;
		}
	}
	return 1;
}

int lcm(int a, int b) {
	return a * b / gcd(a, b);
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	cin >> s;
	int idx = s.find(':');
	int a = stoi(s.substr(0, idx));
	int b = stoi(s.substr(idx + 1));
	cout << (a / gcd(a, b)) << ':' << (b / gcd(a, b)) << '\n';
}

// 정수비를 최대한으로 약분하여 출력하기

// 두 수를 최대공약수로 나누어 출력한다 - 기약분수 만드는 방법!