// 초콜릿 합치기
// https://www.acmicpc.net/problem/34948

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<pr> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].first;
	}
	for (int i = 0; i < n; i++) {
		cin >> v[i].second;
	}
	sort(v.begin(), v.end(), [](pr a, pr b) {
		if (a.first == b.first) {
			return a.second < b.second;
		}
		return a.first > b.first;
	});
	vector<long long> sum(n);
	sum[0] = v[0].second;
	for (int i = 1; i < n; i++) {
		sum[i] = sum[i - 1] + v[i].second;
	}
	long long res = sum[n - 1] * v[n - 1].first;
	for (int i = 0; i < n - 1; i++) {
		if (v[i].first != v[i + 1].first) {
			res = max(res, sum[i] * v[i].first);
		}
	}
	cout << res << '\n';
}

// 세로만 자를 수 있는 가로와 세로 길이가 주어진 초콜릿에서 세로 길이를 통일해서 모을 때, 최대 넓이 구하기