// 젓가락 게임
// https://www.acmicpc.net/problem/25642

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int yt, yj;
	cin >> yt >> yj;
	while (true) {
		yj += yt;
		if (yj >= 5) {
			cout << "yt\n";
			break;
		}
		yt += yj;
		if (yt >= 5) {
			cout << "yj\n";
			break;
		}
	}
}

// yt와 yj가 다른 사람이 펼친 손가락의 수만큼 손가락을 펼치는 게임을 할 때, 상대 손가락을 5개 이상 펼치게 만들어 승리하는 사람 구하기

// 교대로 계속 추가해나가기