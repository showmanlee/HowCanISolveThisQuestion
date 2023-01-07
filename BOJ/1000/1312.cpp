// 소수
// https://www.acmicpc.net/problem/1312

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int a, b, n;
	cin >> a >> b >> n;	
	a %= b;
	int res = 0;
	for (int i = 0; i < n; i++) {
		a *= 10;
		res = a / b;
		a %= b;
	}
	cout << res << '\n';
}
 
// a / b의 소수 n째자리 수 구하기

// 우리가 손으로 나눗셈을 하는 원리로 풀면 됨 - 안 나누어떨어지면 뒤에 0을 붙여 나누기