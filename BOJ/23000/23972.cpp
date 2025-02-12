// 악마의 제안
// https://www.acmicpc.net/problem/23972

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	long long k, n;
	cin >> k >> n;
	long long res = -1;
	if (n > 1) {
		res = (k * n) / (n - 1);
		if ((k * n) % (n - 1) > 0) {
			res += 1;
		}
	}
	cout << res << '\n';
}

// k원을 내고 남은 금액을 n배로 불려줄 떄, 손해를 보지 않기 위해 필요한 액수 구하기