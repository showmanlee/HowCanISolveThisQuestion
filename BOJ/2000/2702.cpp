// 초6 수학
// https://www.acmicpc.net/problem/2702

#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
	if (a < b)
		swap(a, b);
	while (b != 0) {
		int t = a % b;
		a = b;
		b = t;
	}
	return a;
}

int lcm(int a, int b) {
	return a * b / gcd(a, b);
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		cout << lcm(a, b) << ' ' << gcd(a, b) << '\n';
	}
}

// 두 수의 최소공배수, 최대공약수 출력하기
// 잊지 않고 써먹을 수 있도록 하자