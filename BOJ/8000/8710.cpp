// Koszykarz
// https://www.acmicpc.net/problem/8710

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	int a, b, c;
	cin >> a >> b >> c;
	int res = (b - a) / c + ((b - a) % c > 0 ? 1 : 0);
	cout << res << '\n';
}

// a를 b 이상으로 만들기 위해 c를 더해야 하는 횟수 구하기

// 계산해봐요