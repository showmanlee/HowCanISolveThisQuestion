// Sun and Moon
// https://www.acmicpc.net/problem/27590

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int ax, ay, bx, by;
	cin >> ax >> ay >> bx >> by;
	int a = ay - ax;
	int b = by - bx;
	while (a != b) {
		if (a < b) {
			a += ay;
		} else {
			b += by;
		}
	}
	cout << a << '\n';
}

// 해와 달의 공전 주기와 현재 위치가 주어질 때, 월식 발생 시점 구하기