// 영수증
// https://www.acmicpc.net/problem/25304

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int p;
	cin >> p;
	int sum = 0;
	for (int i = 0; i < p; i++) {
		int a, b;
		cin >> a >> b;
		sum += a * b;
	}
	cout << (n == sum ? "Yes" : "No") << '\n';
}

// 물건의 총 금액과 구매 현환이 주어질 때, 정확한지 확인하기

// 계산을 해봅시다~ - 맞는지 안 맞는지