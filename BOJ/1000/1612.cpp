// 가지고 노는 1
// https://www.acmicpc.net/problem/1612

#include <iostream>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	if (n % 2 == 0 || n % 5 == 0)
		cout << -1 << '\n';
	else {
		int res = 1, one = 1;
		while (one % n != 0) {
			one %= n;
			one = one * 10 + 1;
			res++;
		}
		cout << res << '\n';
	}
}

// 어떤 수의 배수 중 1만 들어간 숫자가 있는가? 있다면 1이 몇 개 있는가?
// 수학적 접근이 필요합니다
// 우선 2나 5의 배수일 경우 끝자리가 짝수 또는 5/0이 나오기 때문에 무조건 1이 나오지 않음
// 1을 늘려가면서 나머지 연산을 하려고 하면 시간 오류가 날 수 있기에 나머지의 성질을 활용하자
// (a % b) * 10 == (a * 10) % b, (a % b) + 1 - (a + 1) % b
// 따라서 (a % b)를 구한 후 이를 * 10 + 1한 값을 활용하면 자릿수가 올라가는 상황에서 나누어떨어지는지 확인할 수 있다