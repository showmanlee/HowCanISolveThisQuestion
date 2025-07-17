// 클리크 조절
// https://www.acmicpc.net/problem/33884

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	long long ax = 0, ay = 0, bx = 0, by = 0;
	for (int i = 0; i < n; i++) {
		long long x, y;
		cin >> x >> y;
		ax += x;
		ay += y;
	}
	for (int i = 0; i < n; i++) {
		long long x, y;
		cin >> x >> y;
		bx += x;
		by += y;
	}
	long long xx = bx - ax;
	long long yy = by - ay;
	xx /= n;
	yy /= n;
	cout << xx << ' ' << yy << '\n';
}

// n번의 사격을 2번 한 결과가 주어질 때, 각 회차간 이동한 좌표 거리 출력하기