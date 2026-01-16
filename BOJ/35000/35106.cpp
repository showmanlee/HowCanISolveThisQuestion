// 릴레이 가위바위보 게임
// https://www.acmicpc.net/problem/35106

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> cnt(4);
	for (int i = 0; i < n * 3; i++) {
		int p;
		cin >> p;
		cnt[p]++;
	}
	int resa = 0, resb = 0;
	for (int i = 1; i <= 3; i++) {
		if (cnt[i] == n - 1) {
			resa = i;
		} else if (cnt[i] == n + 1) {
			resb = i;
		}
	}
	cout << resa << '\n' << resb << '\n';
}

// 1/2/3을 3n번 동안 정확히 n번씩 내려 할 때, 잘못낸 1가지와 고칠 것 구하기