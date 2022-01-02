// N과 M (11)
// https://www.acmicpc.net/problem/15665

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
			if (prev != t[i]) {
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

// 중복이 포함된 N가지의 자연수 중 중복 포함하여 M개를 고른 수열을 출력하기
// 범위가 7까지니까 재귀로 처리 가능
// 중복된 수열은 출력되면 안 되지만, 한 수열 내에 중복된 숫자가 나올 수 있음 - 입력 단에서 중복 처리를 하면 안됨
// 직전에 골랐던 수를 저장하는 부분을 추가해 수열 생성 과정에서 핸들링
// 그래도 이번엔 check 배열은 필요없음

// N과 M 시리즈 끝 + 400문제 돌파(어느새)