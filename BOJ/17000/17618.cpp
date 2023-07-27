// 신기한 수
// https://www.acmicpc.net/problem/17618

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> v(n + 1);
	for (int i = 1; i <= n; i++) {
		int p = i;
		int t = 0;
		while (p > 0) {
			t += p % 10;
			p /= 10;
		}
		v[i] = v[i - 1] + (i % t == 0 ? 1 : 0);
	}
	cout << v[n] << '\n';
}

// 1부터 n까지의 자연수 중 자릿수의 합으로 나누어떨어지는 자연수의 개수 구하기

// 직접 구해보면 됩니다