// Amusement Park Adventure
// https://www.acmicpc.net/problem/29986

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;
	int res = 0;
	for (int i = 0; i < n; i++) {
		int p;
		cin >> p;
		if (p <= k) {
			res++;
		}
	}
	cout << res << '\n';
}

// 자신의 키가 주어질 때, 이어서 주어지는 놀이기구의 최소 키에 대해 탈 수 있는 개수 구하기