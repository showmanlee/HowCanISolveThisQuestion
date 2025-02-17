// Hay Bales
// https://www.acmicpc.net/problem/5919

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
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		sum += v[i];
	}
	sum /= n;
	int res = 0;
	for (int i = 0; i < n; i++) {
		res += max(0, sum - v[i]);
	}
	cout << res << '\n';
}

// 수열의 모든 수를 동일하게 맞추기 위해 필요한 이동 횟수 구하기