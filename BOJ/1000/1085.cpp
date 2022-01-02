// 직사각형에서 탈출
// https://www.acmicpc.net/problem/1085

#include <iostream>
using namespace std;

int main(void) {
	int x, y, w, h;
	cin >> x >> y >> w >> h;
	int xl = (x < w - x ? x : w - x);
	int yl = (y < h - y ? y : h - y);
	cout << (xl < yl ? xl : yl) << '\n';
}