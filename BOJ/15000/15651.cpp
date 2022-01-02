// N과 M (3)
// https://www.acmicpc.net/problem/15651

#include <iostream>
#include <vector>
using namespace std;

int n, m;

void nm(vector<int> v, int k) {
	if (k == m) {
		for (int i : v)
			cout << i << ' ';
		cout << '\n';
	}
	else {
		for (int i = 1; i <= n; i++) {
			v[k] = i;
			nm(v, k + 1);
		}
	}
}

int main(void) {
	cin >> n >> m;
	vector<int> v(m);
	for (int i = 1; i <= n; i++) {
		v[0] = i;
		nm(v, 1);
	}
}

// N까지의 자연수 중 중복 포함하여 M개를 고른 수열 출력하기
// 범위가 7까지니까 재귀로 처리 가능
// 재귀로 깊이를 결정하는 반복문