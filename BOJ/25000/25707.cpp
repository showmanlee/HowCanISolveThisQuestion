// 팔찌 만들기
// https://www.acmicpc.net/problem/25707

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
	for (int i = 1; i < n; i++) {
		res += v[i] - v[i - 1];
	}
	res += v[n - 1] - v[0];
	cout << res << '\n';
}

// 주어진 원형 수열의 원소간 차의 절댓값의 합을 최소로 하는 결과 출력하기