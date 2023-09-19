// 줄줄이 박수
// https://www.acmicpc.net/problem/29718

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<int> cnt(m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int p;
			cin >> p;
			cnt[j] += p;
		}
	}
	int a;
	cin >> a;
	int cur = 0;
	for (int i = 0; i < a; i++) {
		cur += cnt[i];
	}
	int res = cur;
	for (int i = 0; i < m - a; i++) {
		cur -= cnt[i];
		cur += cnt[i + a];
		res = max(res, cur);
	}
	cout << res << '\n';
}

// n*m 보드가 주어질 때, 연속된 a개 열의 합이 가장 큰 경우 구하기

// 슬라이딩 윈도우 - 행은 신경쓸 필요 없으므로 미리 모두 더해둔다