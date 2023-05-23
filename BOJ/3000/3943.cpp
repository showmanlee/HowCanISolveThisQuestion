// 헤일스톤 수열
// https://www.acmicpc.net/problem/3943

#include <iostream>
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
		int res = p;
		while (p != 1) {
			if (p % 2) {
				p = p * 3 + 1;
			} else {
				p /= 2;
			}
			res = max(res, p);
		}
		cout << res << '\n';
	}
}

// p부터 시작해 p가 홀수일 때는 p * 3 + 1, 짝수일 때는 p / 2를 하는 수열이 있을 때, 수열이 1에 도달할 때 까지 만들어지는 수 중 가장 큰 수는?

// 직접 돌려보세요