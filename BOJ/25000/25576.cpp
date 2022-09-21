// 찾았다 악질
// https://www.acmicpc.net/problem/25576

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<int> v(m);
	for (int i = 0; i < m; i++) {
		cin >> v[i];
	}
	int cnt = 0;
	for (int i = 1; i < n; i++) {
		int sum = 0;
		for (int j = 0; j < m; j++) {
			int p;
			cin >> p;
			sum += abs(p - v[j]);
		}
		if (sum > 2000) {
			cnt++;
		}
	}
	cout << ((cnt >= (n - 1) / 2.0) ? "YES" : "NO") << '\n';
}

// 주어진 기간 중 시청자 추이의 차의 합이 2000을 넘는 스트리머 수가 절반 이상인지 판정하기

// 차의 절댓값 합을 보고 2000 이상이면 카운트에 넣어, 카운트가 (n - 1) / 2 이상인지 보기
// 입력을 많이 받긴 하지만 원리는 간단한 문제랍니다