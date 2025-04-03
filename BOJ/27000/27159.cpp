// 노 땡스!
// https://www.acmicpc.net/problem/27159

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int prev = 0;
	int res = 0;
	for (int i = 0; i < n; i++) {
		int p;
		cin >> p;
		if (p > prev + 1) {
			res += p;
		}
		prev = p;
	}
	cout << res << '\n';
}

// 노 땡스 게임에서 갖고 있는 카드가 주어질 때, 최종 점수 출력하기