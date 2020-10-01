// 숫자
// https://www.acmicpc.net/problem/10093

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	long long a, b;
	cin >> a >> b;
	if (a > b)
		swap(a, b);
	cout << (a == b ? 0 : b - a - 1) << endl;
	for (long long i = a + 1; i < b; i++)
		cout << i << ' ';
	cout << endl;
}

// a가 b보다 항상 작지는 않다
// 최댓값이 10^15이기 때문에 int로 커버 불가능
// a == b일때 핸들링 필요