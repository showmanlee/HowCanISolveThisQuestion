// 배시와 데이지
// https://www.acmicpc.net/problem/16431

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int bx, by, dx, dy, jx, jy;
	cin >> bx >> by >> dx >> dy >> jx >> jy;

	int br = max(abs(bx - jx), abs(by - jy));
	int dr = abs(dx - jx) + abs(dy - jy);

	if (br < dr)
		cout << "bessie\n";
	else if (br > dr)
		cout << "daisy\n";
	else
		cout << "tie\n";
}

// 8방향으로 움직일 수 있는 베시와 4방향으로 움직일 수 있는 데이지가 존에게 갈 때, 누가 먼저 도착할까?
// 장애물이 없는 보드에서 4방향 이동 시 최소 거리는 두 좌표축의 차의 합
// 8방향의 경우에는 x축과 y축을 함께 이동할 수 있으므로 두 좌표축의 차 중 큰 값이 된다