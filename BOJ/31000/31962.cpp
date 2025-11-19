// 등교
// https://www.acmicpc.net/problem/31962

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, x;
	cin >> n >> x;
	int res = -1;
	for (int i = 0; i < n; i++) {
		int s, t;
		cin >> s >> t;
		if (s + t <= x) {
			res = max(res, s);
		}
	}
	cout << res << '\n';
}

// 제한 시간과 버스 출발 시간이 주어질 때 가장 늦게 출발하면서 시간 안에 도착하는 버스 고르기