// 블랙잭
// https://www.acmicpc.net/problem/2798

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int n, m, res = 0;
	cin >> n >> m;
	vector<int> cards(n);
	for (int i = 0; i < n; i++)
		cin >> cards[i];
	for (int i = 0; i < n - 2; i++)
		for (int j = i + 1; j < n - 1; j++)
			for (int k = j + 1; k < n; k++) {
				int p = cards[i] + cards[j] + cards[k];
				if (p <= m && res < p)
					res = p;
				if (res == m) {
					cout << res << '\n';
					return 0;
				}
			}
	cout << res << '\n';
	return 0;
}

// 카드가 100개라 n^3로 풀 수 있음 - 문제 자체도 브루트포스