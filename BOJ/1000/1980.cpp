// 햄버거 사랑
// https://www.acmicpc.net/problem/1980

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, t;
	cin >> n >> m >> t;
	if (n > m) {
		swap(n, m);
	}
	int cnt = t / n;
	int resc = cnt;
	int res = t - (n * cnt);
	for (int i = cnt; i >= 0; i--) {
		int p = n * i;
		int c = i + ((t - p) / m);
		int q = p + (((t - p) / m) * m);
		if (t - q < res) {
			res = t - q;
			resc = c;
		} else if (t - q == res && c > resc) {
			resc = c;
		}
	}
	cout << resc << ' ' << res << '\n';
}

// t분 안에 각각 n, m분 만에 먹을 수 있는 버거를 최대한 쉬지 않고 먹었을 때 나올 수 있는 햄버거 갯수와 쉰 시간 구하기