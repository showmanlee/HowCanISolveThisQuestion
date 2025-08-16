// 겹치는 건 싫어
// https://www.acmicpc.net/problem/20922

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	vector<int> cnt(100001);
	int l = 0, r = 1;
	int res = 1;
	cnt[v[0]]++;
	while (r < n) {
		cnt[v[r]]++;
		if (cnt[v[r]] > k) {
			cnt[v[r]]--;
			cnt[v[l]]--;
			l++;
		} else {
			r++;
		}
		res = max(res, r - l);
	}
	cout << res << '\n';
}

// 주어진 수열에서 같은 원소가 k개 이하로 있는 가장 긴 연속 부분 수열의 길이 출력하기