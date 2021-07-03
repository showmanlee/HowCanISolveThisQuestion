// 분수 합
// https://www.acmicpc.net/problem/1735

#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
	if (a < b)
		swap(a, b);
	while (b != 0) {
		int p = a % b;
		a = b;
		b = p;
	}
	return a;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int aa, ab, ba, bb;
	cin >> aa >> ab >> ba >> bb;
	int ra = (aa * bb) + (ab * ba), rb = ab * bb;
	int g = gcd(ra, rb);
	ra /= g;
	rb /= g;
	cout << ra << ' ' << rb;
}

// 두 분수의 합을 기약분수로 출력하기

// 두 분수를 받고, 기약분수가 아닐 수 있는 분수 합을 만든다 - 분모는 두 분모의 곱, 분자는 내 분자와 상대 분모의 곱의 합
// 이후 분모와 분자의 최대공약수를 뽑은 뒤, 분모와 분자를 최대공약수로 나눈 뒤 출력한다