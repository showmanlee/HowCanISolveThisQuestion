// 펭귄추락대책위원회
// https://www.acmicpc.net/problem/18228

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> v(n);
	int k = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		if (v[i] == -1) {
			k = i;
		}
	}
	int l = 1987654321;
	int r = 1987654321;
	for (int i = 0; i < k; i++) {
		l = min(l, v[i]);
	}
	for (int i = k + 1; i < n; i++) {
		r = min(r, v[i]);
	}
	cout << (l + r) << '\n';
}

// 양끝으로 고정되어 있고 각 칸마다 경도가 다른 n칸 길이 얼음판 위 한 칸에 놓인 펭귄을 떨어뜨리는데 드는 얼음의 최소 경도 구하기