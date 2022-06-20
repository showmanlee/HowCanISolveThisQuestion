// 99 Problems
// https://www.acmicpc.net/problem/25270

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int a = (n / 100 - 1) * 100 + 99;
	int b = (n / 100) * 100 + 99;
	if (a <= 0 || abs(a - n) >= abs(b - n)) {
		cout << b << '\n';
	} else {
		cout << a << '\n';
	}
}

// 주어진 수에 더하거나 빼서 끝자리를 99로 만든 수 중에 양수이면서 가장 가까운 값은(동률이면 큰 값)?

// 빼서 99로 만든 케이스와 더해서 99로 만든 케이스를 구한 후, 차가 더 적은 쪽을 출력한다
// 빼서 만든 케이스는 백의 자리를 하나 빼고 99로 만들고, 더해서 만든 케이스는 그냥 99로 만든다