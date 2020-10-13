// 소수 구하기
// https://www.acmicpc.net/problem/1929

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

bool prime(int n) {
	if (n == 1)
		return false;
	for (int i = 2; i <= sqrt(n); i++)
		if (n % i == 0)
			return false;
	return true;
}

int main(void) {
	int a, b;
	vector<int> p;
	cin >> a >> b;
	for (int i = a; i <= b; i++)
		if (prime(i))
			p.push_back(i);
	for (int i = 0; i < p.size(); i++)
		cout << p[i] << '\n';
}