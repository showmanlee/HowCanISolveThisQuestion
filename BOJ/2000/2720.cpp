// 세탁소 사장 동혁
// https://www.acmicpc.net/problem/2720

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		int n;
		cin >> n;
		cout << (n / 25) << ' ';
		n %= 25;
		cout << (n / 10) << ' ';
		n %= 10;
		cout << (n / 5) << ' ';
		n %= 5;
		cout << n << '\n';
	}
}

// 25센트, 10센트, 5센트, 1센트 동전이 있을 때, 거슬러줘야 할 금액이 주어졌을 때 동전 개수를 최소화하여 거슬러주기 위해 필요한 각 동전의 개수는?

// 당연히 가능한 큰 동전을 쓰는 것이 이득 - 따라서 25 10 5 1 순으로 나눈 몫을 출력하고, 다음 동전으로 넘어갈 때는 해당 금액을 이전 동전의 나머지로 바꾸기