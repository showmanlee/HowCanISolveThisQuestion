// 복권
// https://www.acmicpc.net/problem/1359

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cout << fixed;
    cout.precision(16);

	vector<double> fact(9);
	fact[0] = 1;
	fact[1] = 1;
	for (int i = 2; i <= 8; i++) {
		fact[i] = fact[i - 1] * i;
	}
	
	int n, m, k;
	cin >> n >> m >> k;
	double res = 0;
	double p = fact[n] / (fact[n - m] * fact[m]);
	while (m >= k) {
		if (n - m < m - k) {
			k++;
			continue;
		}
		double d = (fact[m] / (fact[m - k] * fact[k])) * (fact[n - m] / (fact[(n - m) - (m - k)] * fact[m - k]));
		res += d / p;
		k++;
	}
	cout << res << '\n';
}

// n개의 수 중 m개의 숫자를 뽑는데, 그 중 k개 이상의 수가 맞으면 당첨인 복권의 당첨 확률은?

// 조합을 이용해서 풀어볼 수 있음
// n개 중 m개를 뽑는 경우의 수(= n-m개의 나머지가 뽑히는 경우의 수) = nCm
// 그리고 m개 중에서 k개를 뽑는 경우의 수 = mCk, 나머지 n-m개 중 k개가 선택되지 않는 경우의 수 = n-mCm-k
// 따라서 확률은 mCk * n-mCm-k / nCm - 간단한 경우의 수를 그려보면 됨
// 그리고 k개 이상이라고 했으니 k에서 m까지 저 값을 구해줘야 함 - 다만 n-m이 m-k보다 작아지면 조합을 구할 수 없으므로 패스
// nCm = n! / ((n-m)! * m!)