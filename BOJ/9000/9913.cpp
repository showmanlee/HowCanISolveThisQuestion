// Max
// https://www.acmicpc.net/problem/9913

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> cnt(1001);
	int res = 0;
	for (int i = 0; i < n; i++) {
		int p;
		cin >> p;
		cnt[p]++;
		res = max(res, cnt[p]);
	}
	cout << res << '\n';
}

// 주어지는 자연수들 중 등장 빈도가 가장 높은 수의 빈도 출력하기

// 주어지는 수 범위기 1~1000이므로 빈도를 배열로 셀 수 있음
// 배열 속 최댓값 출력하기