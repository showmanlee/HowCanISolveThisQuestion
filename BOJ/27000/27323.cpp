// 長方形 (Rectangle)
// https://www.acmicpc.net/problem/27323

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a, b;
	cin >> a >> b;
	cout << (a * b) << '\n';
}

// 직사각형의 가로와 세로가 주어졌을 때, 넓이 구하기