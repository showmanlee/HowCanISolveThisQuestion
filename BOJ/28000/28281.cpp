// 선물
// https://www.acmicpc.net/problem/28281

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	int n, x;
	cin >> n >> x;
	vector<int> v(n);
	int res = INT_MAX;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		if (i > 0) {
			res = min(res, (v[i] + v[i - 1]) * x);
		}
	}
	cout << res << '\n';
}

// 매일의 양말 값 현황이 주어지고 연속된 이틀 동안 각각 x개의 양말을 살 때, 최저가 구하기

// 연속된 이틀의 합의 최소 구하기