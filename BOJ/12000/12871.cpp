// 무한 문자열
// https://www.acmicpc.net/problem/12871

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
	if (a < b)
		swap(a, b);
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int lcm(int a, int b) {
	return a * b / gcd(a, b);
}

int main(void) {
	string a, b;
	cin >> a >> b;
	int l = lcm(a.length(), b.length());
	int la = l / a.length(), lb = l / b.length();
	string aa, bb;
	for (int i = 0; i < la; i++)
		aa += a;
	for (int i = 0; i < lb; i++)
		bb += b;
	cout << (aa == bb) << '\n';
}

// 두 문자열을 무한 번 반복하여 늘렸을 때, 같은 문자열이 되는가?
// 두 문자열을 lcm(len(a), len(b))로 늘려서 같은지 확인하기