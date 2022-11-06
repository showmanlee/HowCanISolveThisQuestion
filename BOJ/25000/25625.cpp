// 샤틀버스
// https://www.acmicpc.net/problem/25625

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a, b;
	cin >> a >> b;
	if (a > b) {
		cout << (a + b) << '\n';
	} else {
		cout << (b - a) << '\n';
	}
}

// 출발지와 도착지를 a분 단위로 운행하는 버스가 현재 도착지에 b분 후 도착할 때, 출발지에서 버스를 기다리는 시간 구하기

// a > b라면 현재 버스는 출발지를 지나 도착지로 가고 있는 중이기에 도착지까지 찍고 다시 돌아와야 탈 수 있음
// a <= b라면 현재 버스는 이미 도착지에서 출발지고 오고 있다는 뜻이므로 출발지로 올 때까지만 기다리면 됨