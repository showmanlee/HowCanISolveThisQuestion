// 수들의 합 2
// https://www.acmicpc.net/problem/2003

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<int> v(n + 1);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	int f = 0, r = 0;
	int sum = v[0];
	int res = 0;
	while (r < n) {
		if (sum == m) {
			res++;
		}
		if (f == r || sum <= m) {
			r++;
			sum += v[r];
		} else {
			sum -= v[f];
			f++;
		}
	}
	cout << res << '\n';
}

// 주어진 수열에서 연속된 수의 합이 m이 되는 경우의 수는?

// 수열의 길이가 10000이라서 n^2로는 당연히 안 됨 - 연속된 수를 더하는 것이므로 front-rear 포인터를 사용해볼 수 있음
// 시작은 두 포인터 모두 0, rear가 바깥으로 나갈 때 종료
// 합이 m이 되면 경우의 수 추가, 그리고 합이 m 이하라면 rear를 밀고, 아니라면 front를 밀어 합에 더하거나 뺀다