// 배수들의 합
// https://www.acmicpc.net/problem/17173

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	int res = 0;
	vector<int> k(m);
	for (int i = 0; i < m; i++) {
		cin >> k[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			if (i % k[j] == 0) {
				res += i;
				break;
			}
		}
	}
	cout << res << '\n';
}

// 1부터 n까지의 자연수 중 m개의 자연수 풀의 배수인 수의 합은?

// 자연수 풀을 배열로 받고, 1부터 n까지 돌려서 배수인지 확인한다