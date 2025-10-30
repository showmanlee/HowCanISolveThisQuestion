// Mult!
// https://www.acmicpc.net/problem/24408

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int p = 0;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		if (p == 0) {
			p = t;
		} else if (t % p == 0) {
			cout << t << '\n';
			p = 0;
		}
	}
}

// 주어지는 수들에서 첫 번째로 부른 수의 배수가 나왔을 때 그 수를 출력하고 다음 수를 다시 '첫 번째' 수로 만들 때, 출력되는 수들 구하기