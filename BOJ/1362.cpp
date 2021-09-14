// 펫
// https://www.acmicpc.net/problem/1362

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int idx = 0;
	while (true) {
		idx++;
		int o, w;
		cin >> o >> w;
		if (o == 0 && w == 0)
			break;
		while (true) {
			char c;
			int p;
			cin >> c >> p;
			if (c == '#' && p == 0)
				break;
			if (w <= 0)
				continue;
			if (c == 'E')
				w -= p;
			else if (c == 'F')
				w += p;
		}
		cout << idx << ' ';
		if (w > o / 2 && w < o * 2)
			cout << ":-)\n";
		else if (w <= 0)
			cout << "RIP\n";
		else
			cout << ":-(\n";
	}
}

// 기르는 펫의 체중을 늘리거나 줄이는 게임에서 펫은 적정 체중의 1/2~2배 사이에 있다면 행복한 상태, 0 이하면 죽은 상태, 그 외의 상태라면 슬픈 상태가 될 때, 주어진 명령을 수행했을 때 펫의 상태 출력하기

// 입력이 들어오는대로 펫의 체중을 조절하면 됨
// 다만 체중이 0이 되는 순간 펫이 사망하여 어떠한 행동도 할 수 없게 되므로, 입력이 들어오는 시점에서 체중이 0이라면 다른 행동을 하지 않는다