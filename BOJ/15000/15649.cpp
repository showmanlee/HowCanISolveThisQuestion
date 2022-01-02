// N과 M (1)
// https://www.acmicpc.net/problem/15649

#include <iostream>
#include <vector>
using namespace std;

int n, m;

void nm(vector<int> v, vector<bool> check, int k) {
	if (k == m) {
		for (int i : v)
			cout << i << ' ';
		cout << '\n';
	}
	else {
		for (int i = 1; i <= n; i++) {
			if (!check[i - 1]) {
				v[k] = i;
				check[i - 1] = true;
				nm(v, check, k + 1);
				check[i - 1] = false;
			}
		}
	}
}

int main(void) {
	cin >> n >> m;
	vector<int> v(m);
	vector<bool> check(n);
	for (int i = 1; i <= n; i++) {
		v[0] = i;
		check[i - 1] = true;
		nm(v, check, 1);
		check[i - 1] = false;
	}
}

// N까지의 자연수 중 M개를 고른 수열 출력하기
// 범위가 8까지니까 재귀로 처리 가능
// check 배열을 통해 중복 체크하기 - 재귀 나온 후에는 check 해제