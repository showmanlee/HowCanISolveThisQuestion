// Завоеватель
// https://www.acmicpc.net/problem/29354

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int p;
	cin >> p;
	long long res = 0;
	for (int i = 1; i < n; i++) {
		int t;
		cin >> t;
		res += p;
		p = min(p, t);
	}
	cout << res << '\n';
}

// 왼쪽에서 오른쪽까지 이동하는 상황에서 말을 갈아탈 수 있을 때, 최소 시간 구하기