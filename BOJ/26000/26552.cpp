// Zero
// https://www.acmicpc.net/problem/26552

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		int p;
		cin >> p;
		p++;
		int d = 1;
		while (d <= p) {
			if (p / d % 10 == 0) {
				p += d;
			}
			d *= 10;
		}
		cout << p << '\n';
	}
}

// 주어진 수 다음으로 등장할 0이 없는 수 구하기