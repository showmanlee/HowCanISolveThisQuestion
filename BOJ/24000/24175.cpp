// Tokyo2020
// https://www.acmicpc.net/problem/24175

#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	while (true) {
		int n;
		cin >> n;
		if (n == 0) {
			break;
		}
		int resa = 987654321, maxa = 0, resb = 987654321, maxb = 0;
		map<int, int> cnt, gold;
		for (int i = 0; i < n; i++) {
			int p;
			string a, b;
			cin >> p >> a >> b;
			cnt[p]++;
			if (b == "Gold") {
				gold[p]++;
			}
			if (maxa < cnt[p]) {
				resa = p;
				maxa = cnt[p];
			} else if (maxa == cnt[p]) {
				resa = min(p, resa);
			}
			if (maxb < gold[p]) {
				resb = p;
				maxb = gold[p];
			} else if (maxb == gold[p]) {
				resb = min(p, resb);
			}
		}
		cout << resb << ' ' << resa << '\n';
	}
}

// 1차원 좌표를 s에서 오른쪽 왼쪽으로 1칸씩 왔다갔다 할 때, l 또는 r에 가장 먼저 닿는 턴 수 구하기