// Polynomial
// https://www.acmicpc.net/problem/19575	

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<long long, long long> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	long long n, x;
	cin >> n >> x;
	vector<pr> v(n + 1);
	for (int i = 0; i <= n; i++) {
		cin >> v[i].first >> v[i].second;
	}
	long long res = v[0].first;
	for (int i = 1; i <= n; i++) {
		res *= x;
		res += v[i].first;
		res %= 1000000007;
	}
	cout << res << '\n';
}

// 주어진 방식으로 다항식 계산하기