// 동전 복사
// https://www.acmicpc.net/problem/28063

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int x, y;
	cin >> x >> y;

	int res = 0;
	if (x > 1) {
		res++;
	}
	if (x < n) {
		res++;
	}
	if (y > 1) {
		res++;
	}
	if (y < n) {
		res++;
	}
	cout << res << '\n';
}

// n*n 보드의 (x,y)에 동전 하나가 놓여 있고, 상하좌우로 동전을 끝까지 움직이면 궤적에 동전들이 놓일 때, 보드에 동전을 모두 채우기 위해 필요한 최소 조작 수 구하기

// 상하좌우 한 번씩만 움직여주면 동전이 모두 채워지게 되어 있음
// 물론 동전이 가장자리에 있으면 가장자리 방향으로는 동전을 움직일 필요가 없음 - 이걸 보고 카운팅해주면 됨