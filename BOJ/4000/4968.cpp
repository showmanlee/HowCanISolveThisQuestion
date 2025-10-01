// Equal Total Scores
// https://www.acmicpc.net/problem/4968

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	while (true) {
		int n, m;
		cin >> n >> m;
		if (n == 0 && m == 0) {
			break;
		}

		vector<int> a(n), b(m);
		int suma = 0, sumb = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			suma += a[i];
		}
		for (int j = 0; j < m; j++) {
			cin >> b[j];
			sumb += b[j];
		}
		int resa = 987654321, resb = 987654321;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (suma - a[i] + b[j] == sumb - b[j] + a[i] && a[i] + b[j] < resa + resb) {
					resa = a[i];
					resb = b[j];
				}
			}
		}
		if (resa == 987654321 && resb == 987654321) {
			cout << -1;
		} else {
			cout<< resa << ' ' << resb;
		}
		cout << '\n';
	}
}

// 키보드에서 영어를 알파벳순으로 바꾼 키보드로 친 문자열이 주어질 때, 원래 문장으로 변형하기