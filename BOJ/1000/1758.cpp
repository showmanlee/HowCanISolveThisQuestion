// 알바생 강호
// https://www.acmicpc.net/problem/1758

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<long long> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end(), greater<long long>());
	long long res = 0;
	for (int i = 0; i < n; i++) {
		res += max(0ll, v[i] - i);
	}
	cout << res << '\n';
}

// 대기열에 선 사람들이 원래 주려고 생각했던 돈 - (받은 등수 - 1) 만큼의 팁을 줄 때, 얻을 수 있는 팁의 최댓값 구하기

// 등수에 따라 팁 공제액이 결정되므로 많이 주려 했던 사람을 앞에 세우는 게 이득