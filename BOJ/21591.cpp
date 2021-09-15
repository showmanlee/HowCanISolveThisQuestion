// Laptop Sticker
// https://www.acmicpc.net/problem/21591

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a, b, c, d;
	cin >> a >> b >> c >> d;
	cout << (a - 2 >= c && b - 2 >= d) << '\n';
}

// 노트북의 크기와 스티커의 크기가 주어졌을 때, 스티커를 노트북 경계와 1cm 이상의 간격을 두면서 붙일 수 있는지 판정하기

// 노트북 가로 - 2가 스티커 가로 이상인지와 노트북 세로 - 2가 스티커 세로 이상인지 판정해서 둘 다 맞으면 합격