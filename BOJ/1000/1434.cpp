// 책 정리
// https://www.acmicpc.net/problem/1434

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<int> box(n), book(m);
	for (int i = 0; i < n; i++) {
		cin >> box[i];
	}
	for (int j = 0; j < m; j++) {
		cin >> book[j];
	}
	int idx = 0;
	int res = 0;
	for (int i = 0; i < m; i++) {
		while (box[idx] < book[i]) {
			res += box[idx];
			idx++;
		}
		box[idx] -= book[i];
	}
	while (idx < n) {
		res += box[idx];
		idx++;
	}
	cout << res << '\n';
}

// 부피가 다른 책들을 주어진 순서대로 주어진 순서대로 나열된 상자에 최대한 넣을 때, 남는 상자 공간 구하기

// 한 번 크기가 넘쳐서 버린 상자는 재사용할 수 없음 - 단방향으로만 봐주면 됨