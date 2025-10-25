// 후문으로
// https://www.acmicpc.net/problem/34544

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int res = 1;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		if (a <= 0) {
			a++;
		}
		if (b <= 0) {
			b++;
		}
		res += b - a;
	}
	if (res <= 0) {
		res--;
	}
	cout << res << '\n';
}

// 어떤 건물의 a층에 있는 정문에서 b층에 있는 후문으로 나갈 때, 1층에서 출발해 모든 건물을 거친 상대 층수 구하기