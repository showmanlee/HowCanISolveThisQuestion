// 도로와 신호등
// https://www.acmicpc.net/problem/2980

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, l;
	cin >> n >> l;
	vector<int> r(l + 1), g(l + 1);
	for (int i = 0; i < n; i++) {
		int d;
		cin >> d;
		cin >> r[d] >> g[d];
	}
	int cnt = 0, pos = 0;
	while (pos < l) {
		cnt++;
		pos++;
		if (r[pos] + g[pos] > 0 && cnt % (r[pos] + g[pos]) < r[pos]) {
			pos--;
		}
		if (pos == l) {
			break;
		}
	}
	cout << cnt << '\n';
}

// 1차원 도로에서 각자 간격대로 바뀌는 신호등이 있을 때, 신호를 지키며 처음부터 끝까지 가는 시간 구하기