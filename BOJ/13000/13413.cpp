// 오셀로 재배치
// https://www.acmicpc.net/problem/13413

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		int n;
		cin >> n;
		string a, b;
		cin >> a >> b;
		int bb = 0, ww = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] != b[i]) {
				if (a[i] == 'B') {
					bb++;
				} else {
					ww++;
				}
			}
		}
		int res = min(bb, ww) + abs(bb - ww);
		cout << res << '\n';
	}
}

// 1차원 오셀로 알 보드에서 두 알의 위치를 바꾸거나 한 알을 뒤집을 수 있을 때, 목표 형태로 바꾸기 위해 필요한 최소 동작 횟수 구하기

// 차이가 나는 칸과 그 종류별 갯수를 구한 뒤, 적은 쪽은 위치를 옮기고, 나머지를 뒤집는다
// 이를 공식으로 만들 수 있음