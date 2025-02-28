// Juta teekond
// https://www.acmicpc.net/problem/32722

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a, b, c;
	cin >> a >> b >> c;
	bool res = ((a == 1 || a == 3) && (b == 6 || b == 8) && (c == 2 || c == 5));
	cout << (res ? "JAH" : "EI") << '\n';
}

// 그림에서 주어진 대로 좌에서 우로 걸을 때, 주어진 대로 숫자 기록이 남을 수 있는지 판정하기