// 미션 도네이션
// https://www.acmicpc.net/problem/25965

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int m;
		cin >> m;
		vector<long long> v(m * 3);
		for (int j = 0; j < m * 3; j++) {
			cin >> v[j];
		}
		int k, d, a;
		cin >> k >> d >> a;
		long long res = 0;
		for (int j = 0; j < m; j++) {
			long long p = v[j * 3] * k - v[j * 3 + 1] * d + v[j * 3 + 2] * a;
			if (p < 0) {
				p = 0;
			}
			res += p;
		}
		cout << res << '\n';
	}
}

// 각 게임에서 K/D/A당 추가/차감/추가하는 돈이 걸린 미션들과 KDA 결과가 주어지고, 각 미션의 결과 총액이 0 미만이면 총합 계산에서 뺄 때, 각 게임의 미션 총 수익 구하기

// 조건이 하나 붙었지만, 차례대로 계산해나가면 됩니다...