// More Dice
// https://www.acmicpc.net/problem/9288

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 1; t <= tt; t++) {
		cout << "Case " << t << ":\n";
		int n;
		cin >> n;
		for (int i = 1; i <= n / 2; i++) {
			int j = n - i;
			if (j <= 6) {
				cout << "(" << i << "," << j << ")\n";
			}
		}
	}
}

// 주어진 수가 나오도록 하는 주사위 2개의 조합 후가 ㅣ