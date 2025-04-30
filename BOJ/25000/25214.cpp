// 크림 파스타
// https://www.acmicpc.net/problem/25214

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
	int minn = v[0];
	vector<int> res(n);
	for (int i = 1; i < n; i++) {
		minn = min(minn, v[i]);
		res[i] = max(res[i - 1], v[i] - minn);
	}
	for (int i = 0; i < n; i++) {
		cout << res[i] << ' ';
	}
	cout << '\n';
}

// 크기가 n인 배열에서 0~i번 원소에서 v[j] - v[i](j > i) 중 최댓값 구하기