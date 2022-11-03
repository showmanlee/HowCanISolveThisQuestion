// Petrol
// https://www.acmicpc.net/problem/18330

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;
	if (n <= 60 + k) {
		cout << (n * 1500);
	} else {
		cout << (1500 * (60 + k) + 3000 * (n - 60 - k)) << '\n';
	}
}

// 60L + 지난 달 이월량만큼의 휘발유는 리터당 1500원, 초과분은 리터당 3000원일 때, 필요한 휘발유의 가격 구하기

// 아까 말한 대로 더해주면 됩니다