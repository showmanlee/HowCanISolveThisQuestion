// Rick-Roll Virus
// https://www.acmicpc.net/problem/29732

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	int n, m, k;
	cin >> n >> m >> k;
	vector<bool> infect(n + 1);
	for (int i = 1; i <= n; i++) {
		char c;
		cin >> c;
		if (c == 'R') {
			for (int j = max(1, i - k); j <= min(n, i + k); j++) {
				infect[j] = true;
			}
		}
	}
	int res = 0;
	for (int i = 1; i <= n; i++) {
		if (infect[i]) {
			res++;
		}
	}
	cout << (res <= m ? "Yes" : "No") << '\n';
}

// 1차원 배열에서 R이 하루 뒤 좌우 k칸 범위로 퍼질 떄, 하루 뒤 퍼진 R이 m개 이하인지 판정하기

// 판정해주세요