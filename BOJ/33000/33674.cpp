// 하늘에서 떨어지는 N개의 별
// https://www.acmicpc.net/problem/33674

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, d, k;
	cin >> n >> d >> k;
	vector<int> v(n), p(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	int res = 0;
	for (int t = 0; t < d; t++) {
		bool reset = false;
		for (int i = 0; i < n; i++) {
			p[i] += v[i];
			if (p[i] + v[i] > k) {
				reset = true;
				break;
			}
		}
		if (reset) {
			for (int i = 0; i < n; i++) {
				p[i] = 0;
			}
			if (t < d - 1) {
				res++;
			}	
		}
	}
	cout << res << '\n';
}

// 각 칸에 일정한 양만큼 쌓이는 배열에서 각 칸의 누적이 k를 넘지 않게 클리어하는 최소 횟수 구하기