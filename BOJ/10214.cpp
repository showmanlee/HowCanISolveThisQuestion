// Baseball
// https://www.acmicpc.net/problem/10214

#include <iostream>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		int y = 0, k = 0;
		for (int i = 0; i < 9; i++) {
			int a, b;
			cin >> a >> b;
			y += a;
			k += b;
		}
		if (y > k)
			cout << "Yonsei\n";
		else if (y < k)
			cout << "Korea\n";
		else
			cout << "Draw\n";
	}
}

// 연세대 vs 고려대 야구 시합에서 각 회에 득점한 점수가 주어졌을 때, 승리 팀은?
// 9회 점수의 합으로 승부