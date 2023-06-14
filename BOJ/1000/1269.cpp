// 대칭 차집합
// https://www.acmicpc.net/problem/1269

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(m);
	map<int, bool> va, vb;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		va[a[i]] = true;
	}
	for (int i = 0; i < m; i++) {
		cin >> b[i];
		vb[b[i]] = true;
	}
	int resa = n, resb = m;
	for (int i = 0; i < n; i++) {
		if (vb[a[i]]) {
			vb[a[i]] = false;
			resb--;
		}
	}
	for (int i = 0; i < m; i++) {
		if (va[b[i]]) {
			va[b[i]] = false;
			resa--;
		}
	}	
	cout << (resa + resb) << '\n';
}

// 자연수 집합 A, B가 있을 때, A-B와 B-A의 원소 갯수의 합 구하기

// 차집합은 배열로 구하기는 범위가 너무 넓으니 map을 이용해서 구하면 된다