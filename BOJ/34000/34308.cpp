// Abby's Absolutes
// https://www.acmicpc.net/problem/34308

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;
	vector<int> v(k);
	for (int i = 0; i < k; i++) {
		cin >> v[i];
	}
	for (int i = 0; i < k; i++) {
		cout << ((abs(v[i] - 1) > abs(v[i] - n)) ? n : 1) << ' ' ;
	}
	cout << '\n';
}

// n*n 보드에 양쪽 대각선에 모두 색을 넣기 위해 필요한 개수 구하기