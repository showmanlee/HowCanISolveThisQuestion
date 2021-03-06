// N과 M (9)
// https://www.acmicpc.net/problem/15663

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;

void nm(vector<int> t, vector<int> v, vector<bool> check, int k) {
	if (k == m) {
		for (int i : v)
			cout << i << ' ';
		cout << '\n';
	}
	else {
		int prev = -1;
		for (int i = 0; i < n; i++) {
			if (prev != t[i] && !check[i]) {
				v[k] = t[i];
				prev = t[i];
				check[i] = true;
				nm(t, v, check, k + 1);
				check[i] = false;
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
	vector<bool> check(n);
	int prev = -1;
	for (int i = 0; i < n; i++) {
		if (prev != t[i]) {
			v[0] = t[i];
			prev = t[i];
			check[i] = true;
			nm(t, v, check, 1);
			check[i] = false;
		}
	}
}

// 중복이 포함되어 있는 N가지의 자연수 중 M개를 고른 수열 출력하기
// 범위가 8까지니까 재귀로 처리 가능
// 중복된 수열은 출력되면 안 되지만, 한 수열 내에 중복된 숫자가 나올 수 있음 - 입력 단에서 중복 처리를 하면 안됨
// 직전에 골랐던 수를 저장하는 부분을 추가해 수열 생성 과정에서 핸들링
// 또한 선택된 수를 저장하는 배열을 만들 수 있다 - 재귀함수 호출 후 비선택 상태로 전환하면 의도한 대로 조작 가능