// Union Maplestory
// https://www.acmicpc.net/problem/28455

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
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end(), greater<int>());
	int resa = 0, resb = 0;
	for (int i = 0; i < min(n, 42); i++) {
		resa += v[i];
		if (v[i] >= 60) {
			resb++;
		}
		if (v[i] >= 100) {
			resb++;
		}
		if (v[i] >= 140) {
			resb++;
		}
		if (v[i] >= 200) {
			resb++;
		}
		if (v[i] >= 250) {
			resb++;
		}
	}
	cout << resa << ' ' << resb << '\n';
}

// 메이플 유니온 공격대에 속한 레벨의 합과 유니온 경험치 증가수 구하기