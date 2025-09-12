// 소트
// https://www.acmicpc.net/problem/1083

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	int s;
	cin >> s;

	int p = 0;
	while (p < n && s > 0) {
		int t = p;
		for (int i = p; i < min(n, p + s + 1); i++) {
			if (v[t] < v[i]) {
				t = i;
			}
		}
		for (int i = t; i > p; i--) {
			swap(v[i - 1], v[i]);
			s--;
		}
		p++;
	}
	for (int i = 0; i < n; i++) {
		cout << v[i] << ' ';
	}
	cout << '\n';
}

// 주어진 배열에서 맞붙은 원소를 최대 s번 스왑할 수 있을 떄, 사전 순으로 가장 뒷서는 배열 출력하기