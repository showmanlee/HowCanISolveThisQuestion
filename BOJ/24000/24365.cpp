// ПЧЕЛИЧКАТА МАЯ
// https://www.acmicpc.net/problem/24365

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a, b, c;
	cin >> a >> b >> c;
	cout << (abs(a - b) + abs(b - c)) << '\n';
}

// 1차원 공간에서 세 벌의 위치가 주어질 때, 세 벌의 위치를 동일하게 하기 위해 움직여야 하는 거리의 합은?

// 가운데 벌에게 양쪽 벌이 이동하면 됨 - 따라서 답은 abs(a - b) + abs(b - c)