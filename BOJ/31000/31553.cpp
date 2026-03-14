// Furiosa AI 영상 처리 가속
// https://www.acmicpc.net/problem/31533

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cout << fixed;
    cout.precision(16);


	double a, m, n;
	cin >> a >> m >> n;
	if (m > n) {
		swap(m, n);
	}
	double res = min(max(m, n / a), m / a * 2.0);
	cout << res << '\n';
}