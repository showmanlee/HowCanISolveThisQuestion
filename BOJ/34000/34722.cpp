// 출제자가 몇 명
// https://www.acmicpc.net/problem/34722

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int res = 0;
	for (int i = 0; i < n; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		if (d == -1) {
			d = 201;
		}
		if (a >= 1000 || b >= 1600 || c >= 1500 || d <= 30) {
			res++;
		}
	}
	cout << res << '\n';
}

// 1부터 n까지의 모든 쌍의 곱의 합 출력하기