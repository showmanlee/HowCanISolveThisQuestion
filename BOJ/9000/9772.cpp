// Quadrants
// https://www.acmicpc.net/problem/9772

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	while (true) {
		float x, y;
		cin >> x >> y;
		if (x == 0 || y == 0) {
			cout << "AXIS\n";
		} else {
			int res = 0;
			if (x > 0 && y > 0) {
				res = 1;
			} else if (x < 0 && y > 0) {
				res = 2;
			} else if (x < 0 && y < 0) {
				res = 3;
			} else {
				res = 4;
			}
			cout << "Q" << res << '\n';
		}
		if (x == 0 && y == 0) {
			break;
		}
	}
}

// 주어진 2차원 좌표가 어떤 사분면에 위치하는지 출력하기

// x,y의 양수/음수 여부를 확인해서 출력 - 0이라면 AXIS 출력하기