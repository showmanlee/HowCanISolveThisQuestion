// 멀티탭 충분하니?
// https://www.acmicpc.net/problem/15780

#include <iostream>
using namespace std;

int main(void) {
	int n, m;
	int sum = 0;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int p;
		cin >> p;
		sum += int(p / 2.0 + 0.5);
	}
	cout << (sum >= n ? "YES\n" : "NO\n");
}

// 모든 사람이 준비된 멀티탭에 콘센트를 꽂을 수 있는가? - 단, 플러그 당 한 칸 이상의 공간이 필요하다
// 3~8구까지 준비되어 있음 - 사용할 수 있는 플러그 수는 ceil(n / 2)