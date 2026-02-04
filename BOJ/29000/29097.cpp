// Короли
// https://www.acmicpc.net/problem/29097

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, k, a, b, c;
	cin >> n >> m >> k >> a >> b >> c;
	int maxx = max(n * a, max(m * b, k * c));
	string res;
	if (maxx == n * a) {
		res += "Joffrey ";
	}
	if (maxx == m * b) {
		res += "Robb ";
	}
	if (maxx == k * c) {
		res += "Stannis ";
	}
	res.pop_back();
	cout << res << '\n';
}

// n * a, m * b, k * c 중 가장 큰 값 구하기