// 가로수
// https://www.acmicpc.net/problem/2485

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
	if (a < b)
		swap(a, b);
	while (b != 0) {
		int t = b;
		b = a % b;
		a = t;
	}
	return a;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> trees(n), dists;
	cin >> trees[0];
	for (int i = 1; i < n; i++) {
		cin >> trees[i];
		dists.push_back(trees[i] - trees[i - 1]);
	}
	int p = dists[0];
	for (int i = 0; i < n - 1; i++)
		p = gcd(p, dists[i]);
	int res = (trees[n - 1] - trees[0]) / p + 1;
	res -= n;
	cout << res << '\n';
}

// 이미 심어진 가로수의 위치들이 주어졌을 떄, 이미 심어진 범위 안에서 추가적으로 가로수를 심어 모든 가로수의 간격을 같게 만들 수 있는 가로수의 수는?

// 이미 심어진 가로수의 간격들을 보고, 이들의 최대공약수를 보면 심어야할 나무 수가 나온다
// 따라서 심어져야 할 나무의 수는 (전체 나무 범위) / 최대공약수 + 1이 되는데, 여기서 이미 심어진 나무 수를 뺴줘야 함