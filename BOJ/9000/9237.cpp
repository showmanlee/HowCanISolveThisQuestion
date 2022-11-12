// 이장님 초대
// https://www.acmicpc.net/problem/9237

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
	sort(v.begin(), v.end(), greater<int>());
	int res = 0;
	for (int i = 0; i < n; i++) {
		res = max(res, v[i] + 2 + i);
	}
	cout << res << '\n';
}

// 하루에 하나씩 심을 수 있는 나무들의 자라는 시간이 주어지고, 심는데 1일이 걸린다고 할 때, 1일차부터 모든 나무가 완전히 자라는데 걸리는 최소 시간은?

// 1일차에 나무를 심는다면 해당 나무는 '심는 시간 1일 + 자라는 시간 + 1일차'에 모두 자란다
// 즉, 나무를 나중에 심을 수록 모두 자라는 일차가 1씩 늘어나는 것 - 이 경우 가장 늦게 자라는 나무를 가장 먼저 심는 게 이득
// 따라서 이런 방식으로 각 나무가 모두 자라는 시점을 구한 후, 이들 중 가장 높은 값이 답이 됨 - 모두 자라야 하니까