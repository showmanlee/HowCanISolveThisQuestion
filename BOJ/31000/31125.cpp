// Dice
// https://www.acmicpc.net/problem/31125

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		int s, n, f, m;
		cin >> s >> n >> f >> m;
		int minn = n + m;
		int maxx = n * f + m;
		bool res = minn <= s && s <= maxx;
		cout << (res ? "YES" : "NO") << '\n';
	}
}

// 정수 s를 f면 주사위 n개에 m을 더해서 만들 수 있는지 구하기