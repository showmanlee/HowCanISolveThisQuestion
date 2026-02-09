// 평행선
// https://www.acmicpc.net/problem/2358

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int res = 0;
	map<long long, int> xv, yv;
	for (int i = 0; i < n; i++) {
		long long x, y;
		cin >> x >> y;
		xv[x]++;
		yv[y]++;
		if (xv[x] == 2) {
			res++;
		}
		if (yv[y] == 2) {
			res++;
		}
	}
	cout << res;
}

// 주어진 점들로 만들 수 있는 축에 평행한 직선의 개수 구하기