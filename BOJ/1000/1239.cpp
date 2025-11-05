// 차트
// https://www.acmicpc.net/problem/1239

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	int res = 0;
	do {
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			int sum = 0;
			int idx = i;
			while (sum < 50) {
				sum += v[idx];
				idx = (idx + 1) % n;
			}
			if (sum == 50) {
				cnt++;
			}
		}
		res = max(res, cnt);
	} while (next_permutation(v.begin(), v.end()));
	res /= 2;
	cout << res << '\n';
}

// 백분율 그래프에서 원을 가로지르는 직선의 최대 갯수 구하기