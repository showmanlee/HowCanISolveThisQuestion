// Saving Princess Peach
// https://www.acmicpc.net/problem/24795

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<int> v(n);
	for (int i = 0; i < m; i++) {
		int p;
		cin >> p;
		v[p] = true;
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (!v[i]) {
			cout << i << '\n';
		} else {
			cnt++;
		}
	}
	cout << "Mario got " << cnt << " of the dangerous obstacles." << '\n';
}

// 0~n-1 중 발견한 m개의 숫자(중복 포함)이 주어질 떄, 발견하지 않은 숫자 및 발견한 숫자 개수 출력하기