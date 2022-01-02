// 3n+1 수열
// https://www.acmicpc.net/problem/14920

#include <iostream>		
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int p;
	cin >> p;
	int n = 1;
	while (p != 1) {
		if (p % 2 == 0)
			p = p / 2;
		else
			p = 3 * p + 1;
		n++;
	}
	cout << n << '\n';
}

// C(n+1) = (C(n) % 2 == 0 ? C(n) / 2 : 3*C(n)+1)로 정의되는 수열의 C(1)이 주어질 때, C(n)이 처음으로 1이 되는 n은?

// 5*2^60 안에서는 언제나 4, 2, 1로 끝난다라고 겁을 주기는 하지만, 주어지는 입력 범위(~100000) 안에서는 while 안에서 처리할 수 있음
// C(1)을 p로 받은 후, p가 1이 될 때까지 p의 상태에 따라 다음 연산을 해준 후 n을 +1해준다