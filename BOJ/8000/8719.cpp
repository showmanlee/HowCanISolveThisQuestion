// Piłeczka
// https://www.acmicpc.net/problem/8719

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		long long x, w;
		cin >> x >> w;
		int res = 0;
		while (true) {
			if (x >= w) {
				break;
			}
			x *= 2;
			res++;
		}
		cout << res << '\n';
	}
}

// 어떤 높이에서 떨어뜨리면 두 배 높이로 튀는 공이 있을 때, x에서 떨어뜨려 w까지 도달하는데 튕겨야 하는 횟수는?

// 계산해보면 됩니다 - 값 범위는 int, 여기서 2배씩 곱해줘야 하므로 안전을 위해 long long으로 두고