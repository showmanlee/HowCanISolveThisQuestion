// N과 M (5)
// https://www.acmicpc.net/problem/15654

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
			if (find(v.begin(), v.begin() + k, t[i]) == v.begin() + k) {
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

// N가지의 자연수 중 M개를 고른 수열 출력하기
// 범위가 8까지니까 재귀로 처리 가능
// 순서가 다르면 다른 순열로 처리됨에 주의 - 인덱스가 아니라 값으로 중복을 판정해야 함