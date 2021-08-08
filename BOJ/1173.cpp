// 운동
// https://www.acmicpc.net/problem/1173

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, M, t, r;
	cin >> n >> m >> M >> t >> r;
	int pulse = m, time = 0, res = 0;
	while (time < n) {
		int npulse = pulse;
		if (npulse + t <= M) {
			npulse += t;
			time++;
		}
		else 
			npulse = max(npulse - r, m);
		if (npulse == pulse) {
			res = -1;
			break;
		}
		res++;
		pulse = npulse;
	}
	cout << res << '\n';
}

// 맥박의 최소치(m)과 최대치(M)을 유지해야 하는 사람이 1분 동안 운동을 하면 t만큼 맥박이 오르고, 쉬면 r만큼 맥박이 내려갈 때, 운동을 총 n분 하기 위해 필요한 시간은?

// 시작 맥박은 m - 운동을 함으로써 증가하는 맥박치가 M을 넘어갈 경우 운동을 할 수 없고, 운동을 안할 때 내려가는 맥박 값은 m 미만으로 내려갈 수 없다
// 이를 고려하여 총 운동 시간이 n이 되기 전까지 while문을 돌려준다 - 운동 가능 조건에 따라 운동을 하거나 쉬고 소요 시간을 흘려주는데, 운동을 했다면 운동 시간을 늘려준다
// 다만 여기서 기본 맥박 + t가 M을 넘어서는 경우가 반복될 경우 운동 자체를 할 수 없어 무한루프에 빠진다 - 따라서 원래 맥박과 변경된 맥박을 따로 계산한 후, 맥박 변화가 없다면 바로 종료해야 함