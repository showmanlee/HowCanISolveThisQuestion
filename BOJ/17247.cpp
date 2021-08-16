// 택시 거리
// https://www.acmicpc.net/problem/17247

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	int ax = -1, ay = -1, bx = -1, by = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int p;
			cin >> p;
			if (p == 1) {
				if (ax == -1) {
					ax = i;
					ay = j;
				}
				else {
					bx = i;
					by = j;
				}
			}
		}
	}
	cout << (abs(bx - ax) + abs(by - ay)) << '\n';
}

// n*m 공간에서 두 점의 맨해튼 거리 구하기

// 맨해튼 거리는 두 점 좌표의 각 축의 차의 절댓값의 합