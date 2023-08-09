// 바구니 순서 바꾸기
// https://www.acmicpc.net/problem/10812

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<int> v(n + 1), temp(n + 1);
	for (int i = 0; i <= n; i++) {
		v[i] = i;
	}
	for (int t = 0; t < m; t++) {
		int i, j, k;
		cin >> i >> j >> k;
		for (int p = i; p <= j; p++) {
			temp[p] = v[p];
		}
		int idx = k;
		for (int p = i; p <= j; p++) {
			v[p] = temp[idx];
			idx++;
			if (idx > j) {
				idx = i;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << v[i] << ' ';
	}
	cout << '\n';
}

// 1~n이 차례대로 담긴 배열에서 n~m칸을 k칸이 앞에 오도록 회전하는 작업을 반복한 후 결과 출력하기

// 시키는 대로 출력해봅시다