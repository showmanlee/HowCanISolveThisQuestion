// 초콜릿 우유가 좋아
// https://www.acmicpc.net/problem/34510

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int h1, h2, h3;
	long long n;
	cin >> h1 >> h2 >> h3 >> n;
	long long res = (n / 2 * (h3 - h1)) + ((n / 2 + (n % 2 == 1 ? 1 : 0)) * (h3 + h2 + h1));
	cout << res << '\n';
}

// 문제에서 주어지는 대로 n층 우유탑을 세울 때 높이 구하기