// 주몽
// https://www.acmicpc.net/problem/1940

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
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	int f = 0, b = n - 1;
	int res = 0;
	while (f < b) {
		if (v[f] + v[b] > m) {
			b--;
		} else if (v[f] + v[b] < m) {
			f++;
		} else {
			res++;
			f++;
			b--;
		}
	}
	cout << res << '\n';
}

// 주어진 수열에서 합이 m이 되는 쌍의 개수는?

// 정렬한 후, 맨 앞과 맨 뒤에서 시작해 경우를 찾아나간다 - 투 포인터