// 지각
// https://www.acmicpc.net/problem/10419

#include <iostream>
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
		int p = 1;
		while(true) {
			if (p + p * p > n) {
				cout << (p - 1) << '\n';
				break;
			}
			p++;
		}
	}
}

// p분을 지각했을 때 p^2분 단축되는 수업이 있을 떄, 수업 시간 n분 중 지각할 수 있는 최대 시간은?

// p + p^2이 n을 초과하는 순간 p-1 출력
// n이 10000까지 주어지므로 최대 100(10100)까지만 계산해주면 됨