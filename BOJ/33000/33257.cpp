// 상현이의 물리학및실험1 실험 대작전
// https://www.acmicpc.net/problem/33257

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, e;
	cin >> n >> e;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	int res = 0;
	for (int i = 0; i < n; i++) {
		res++;
		if (i != n - 1 && v[i + 1] - v[i] < e) {
			res--;
		}
	}
	cout << res << '\n';
}

// n개의 자연수에서 오차범위 e 미만으로 묶을 수 있는 덩어리 개수 구하기