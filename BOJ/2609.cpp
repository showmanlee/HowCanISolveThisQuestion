// 최대공약수와 최소공배수
// https://www.acmicpc.net/problem/2609

#include <iostream>
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
	int a, b;
	cin >> a >> b;
	cout << gcd(a, b) << "\n" << lcm(a, b) << "\n";
}

// 최대공배수는 1부터 둘다 나누어떨어지는지 돌리지 않아도 유클리드 알고리즘으로 얻을 수 있음
// 유클리드 알고리즘: a, b(a > b)이고, a % b = n일 때 n == 0이면 b가 gcd, 아니면 a = b, b = n 대입 후 재계산
// 최소공배수 = a * b / gcd(a, b) - 4 * 6 / 2 = 12