// N과 M (12)
// https://www.acmicpc.net/problem/15666

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
		int prev = -1;
		for (int i = 0; i < n; i++) {
			if (prev != t[i] && v[k - 1] <= t[i]) {
				v[k] = t[i];
				prev = t[i];
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
	int prev = -1;
	for (int i = 0; i < n; i++) {
		if (prev != t[i]) {
			v[0] = t[i];
			prev = t[i];
			nm(t, v, 1);
		}
	}
}

// 중복이 포함되어 있는 N가지의 자연수 중 중복 포함하여 M개를 고른 수열 출력하기
// 범위가 8까지니까 재귀로 처리 가능
// 중복된 수열은 출력되면 안 되지만, 한 수열 내에 중복된 숫자가 나올 수 있음 - 입력 단에서 중복 처리를 하면 안됨
// 또한 순서가 다른 수열도 중복으로 처리됨 - 삽입 과정에서 맨 끝의 원소와 비교 필요