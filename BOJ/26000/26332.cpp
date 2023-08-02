// Buying in Bulk
// https://www.acmicpc.net/problem/26332

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	cout << fixed;
    cout.precision(6);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		int n, p;
		cin >> n >> p;
		cout << n << ' ' << p << '\n' << (p + (p - 2) * (n - 1)) << '\n';
	}
}

// 2개 이상 구입할 경우 추가 구입분이 2달러씩 할인할 때, 물건 구매 개수와 개당 가격을 보고 최종 구매가 출력하기

// 적당히 계산해서 출력해주세요