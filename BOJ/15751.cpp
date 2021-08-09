// Teleportation
// https://www.acmicpc.net/problem/15751

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a, b, x, y;
	cin >> a >> b >> x >> y;
	int res = min(min(abs(a - x) + abs(b - y), abs(a - y) + abs(b - x)), abs(a - b));
	cout << res << '\n';
}

// x와 y가 텔레포터로 이어져있는 1차원 공간에서 a에서 b까지 이동하려고 할 때, 필요한 최소 이동 거리는?

// 일반적인 bfs로도 풀 수 있지만, 거기까지 갈 필요 없이 사칙연산 수준에서도 풀 수 있음
// 어떤 텔레포터 위에 서면 바로 다음 텔레포터 위치로 나오는데, 출발지에서 텔레포터를 타고, 텔레포터에서 나오면 도착지로 바로 이동하는 것이 이득
// 따라서 출발지에서 어떤 텔레포터까지의 거리, 그리고 다른 텔레포터에서 도착지까지의 거리의 합 두 가지 중 최소인 값이 답
// 여기서 텔레포터 자체를 안 타고 바로 이동하는 것이 이득일 수 있으므로 출발지와 도착지의 직선 거리까지 하여 최소인 값이 답이 됨