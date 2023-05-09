// Pokemon Buddy
// https://www.acmicpc.net/problem/18691

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		int g, c, e;
		cin >> g >> c >> e;
		g = 1 + (g - 1) * 2;
		if (e <= c) {
			cout << 0 << '\n';
		} else {
			cout << (g * (e - c)) << '\n';
		}
	}
}

// 주어진 포켓몬과 걸을 때 레벨을 올리는 사탕을 얻는 간격(1/3/5km)와 현재 레벨, 진화에 필요한 레벨이 주어질 때, 포켓몬을 진화시키기 위해 걸어야 하는 길이 출력하기

// 간격 * (목표 - 현재)
// 목표 >= 현재임이 보장되지 않음에 주의