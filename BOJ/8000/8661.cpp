// Stopki
// https://www.acmicpc.net/problem/8661

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int x, k, a;
	cin >> x >> k >> a;
	int res = (x % (k + a) < k);
	cout << res << '\n';
}

// 두 사람이 직선 공간에서 자신의 보폭으로 차례로 가까이 다가갈 때, 누가 먼저 닿는지 구하기