// N과 M (6)
// https://www.acmicpc.net/problem/15655

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;

void nm(vector<int> v, vector<int> t, int k) {
	if (k == m) {
		for (int i : v)
			cout << i << ' ';
		cout << '\n';
	}
	else {
		for (int i = 0; i < n; i++) {
			if (v[k - 1] < t[i]) {
				v[k] = t[i];
				nm(v, t, k + 1);
			}
		}
	}
}

int main(void) {
	cin >> n >> m;
	vector<int> v(m);
	vector<int> t(n);
	for (int i = 0; i < n; i++)
		cin >> t[i];
	sort(t.begin(), t.end());
	for (int i = 0; i < n; i++) {
		v[0] = t[i];
		nm(v, t, 1);
	}
}

// N가지의 자연수 중 중복 포함하여 M개를 고른 수열을 오름차순으로 출력하기
// 범위가 8까지니까 재귀로 처리 가능
// 재귀로 깊이를 결정하는 반복문