// Follow The Prize
// https://www.acmicpc.net/problem/34416

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<bool> v(n + 1);
	int p;
	cin >> p;
	v[p] = true;
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int a, b;
		cin >> a >> b;
		swap(v[a], v[b]);
	}
	for (int i = 1; i <= n; i++) {
		if (v[i]) {
			cout << i << '\n';
			break;
		}
	}
}

// n개의 컵에서 p번째 컵에 공을 넣고 주어진 대로 섞었을 때 공이 있는 위치 구하기