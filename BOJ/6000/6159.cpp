// Costume Party
// https://www.acmicpc.net/problem/6159

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, s;
	cin >> n >> s;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	int res = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (v[i] + v[j] <= s) {
				res++;
			}
		}
	}
	cout << res << '\n';
}

// n개의 자연수 중 두 개를 뽑아 합이 s 이하가 되는 쌍의 수 구하기