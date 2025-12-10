// SCSC 동아리방 방문
// https://www.acmicpc.net/problem/34814

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<int> cnt(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> cnt[i];
	}
	for (int i = 0; i < m; i++) {
		int l, h;
		cin >> l >> h;
		int idx = 0, maxx = 0;
		for (int j = 1; j <= n; j++) {
			if (cnt[j] > maxx) {
				idx = j;
				maxx = cnt[j];
			} else if (cnt[j] == maxx && j == h) {
				idx = h;
			}
		}
		if (idx != h) {
			cnt[l]--;
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << cnt[i] << ' ';
	}
	cout << '\n';
}

// 싫어하는 음료수가 가장 많은 상황에는 음료수를 안 뽑고, 그렇지 않다면 좋아하는 음료수를 뽑을 때, 최종적으로 남은 음료수의 종류별 개수 출력하기