// Piece of Cake!
// https://www.acmicpc.net/problem/17874

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int d, w, h;
	cin >> d >> w >> h;
	w = max(w, d - w);
	h = max(h, d - h);
	int res = w * h * 4;
	cout << res << '\n';
}

// 4cm 두께의 길이 d cm의 정사각형 케이크를 가로 w cm, 세로 h cm 지점에서 자를 때, 얻을 수 있는 가장 큰 조각의 부피는?

// 가로/세로 모두 자른 길이/남은 길이 중 더 긴 쪽을 선택한 뒤, 두께와 함께 부피를 계산한다