// 화살표 연산자
// https://www.acmicpc.net/problem/16114

#include <iostream>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int x, n;
	cin >> x >> n;
	if (x > 0) {
		if (n == 0)
			cout << "INFINITE\n";
		else if (n == 1)
			cout << 0 << '\n';
		else if (n % 2 == 1)
			cout << "ERROR\n";
		else {
			int res = 0;
			x -= n / 2;
			while (x > 0) {
				res++;
				x -= n / 2;
			}
			cout << res << '\n';
		}
	}
	else if (x == 0) {
		if (n == 1)
			cout << 0 << '\n';
		else if (n % 2 == 0)
			cout << 0 << '\n';
		else
			cout << "ERROR\n";
	}
	else {
		if (n % 2 == 0)
			cout << 0 << '\n';
		else if (n == 1)
			cout << "INFINITE\n";
		else
			cout << "ERROR\n";
	}
}

// 변수 x 앞에 -가 n개 붙어있을 때, while(x > 0) cout << x로 나올 수 있는 수의 개수는?

// n == 0이면 x가 감소하지 않으니 무한루프 - INFINITE
// n == 1이면 음수가 되니 수가 출력되지 않음 - 0
// n % 2 == 1이면 -x에 -- 연산을 적용하게 되므로 불가능 - ERROR
// n % 2 == 0이면 제대로 n / 2씩 감소됨 - 수 출력
// 만약 x가 양수인 경우	저런 케이스를 적용할 수 있음 - 그런데 x가 음수일 수도 있음
// 만약 x가 음수인 경우 조건식이 조금 달라짐 - 그래도 x라는 변수에 적용하는 것이기에 -가 하나 더 늘어나는 효과는 아님
// n == 0이면 음수니 수가 출력되지 않음 - 0
// n == 1이면 양수가 되나, 감소되지 않으므로 무한루프 - INFINITE
// n % 2 == 1이면 -x에 -- 연산을 적용하게 되므로 불가능 - ERROR
// n % 2 == 0이면 음수를 감소시키는 것이므로 출력되지 않음 - 0
// x가 0인 경우도 고려해야 함 - 조건식이 x > 0이기 때문에 유효한 경우(n % 2 == 0 || n == 1) 0개 출력, 아니면 ERROR