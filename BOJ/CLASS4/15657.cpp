// N과 M (8)
// https://www.acmicpc.net/problem/15657

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;

void nm(vector<int> t, vector<int> v, int k) {
	if (k == m) {
		for (int i : v)
			cout << i << ' ';
		cout << '\n';
	}
	else {
		for (int i = 0; i < n; i++) {
			if (t[i] >= v[k - 1]) {
				v[k] = t[i];
				nm(t, v, k + 1);
			}
		}
	}
}

int main(void) {
	cin >> n >> m;
	vector<int> t(n);
	for (int i = 0; i < n; i++)
		cin >> t[i];
	sort(t.begin(), t.end());
	vector<int> v(m);
	for (int i = 0; i < n; i++) {
		v[0] = t[i];
		nm(t, v, 1);
	}
}

// N가지의 자연수 중 중복 포함하여 M개를 고른 수열 출력하기
// 범위가 8까지니까 재귀로 처리 가능
// N과 M (4)를 임의의 숫자로 바꾼 버전