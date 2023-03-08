// 트럭 주차
// https://www.acmicpc.net/problem/2979

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a, b, c;
	cin >> a >> b >> c;
	vector<int> start(3), end(3);
	for (int i = 0; i < 3; i++) {
		cin >> start[i] >> end[i];
	}
	int res = 0;
	int cur = 0;
	for (int i = 1; i <= 100; i++) {
		for (int j = 0; j < 3; j++) {
			if (start[j] == i) {
				cur++;
			}
			if (end[j] == i) {
				cur--;
			}
		}
		res += (cur == 1 ? a : cur == 2 ? b : c) * cur;
	}
	cout << res << '\n';
}

// 트럭 3대의 입차/출차 시간이 주어지고, 동시에 1/2/3대 주차했을 때의 대당 1분 주차료가 주어졌을 때, 총 주차료 구하기

// 출차 시간과 입차 시간이 같은 경우는 없으므로, 출차/입차 타이밍을 보고 현재 있는 트럭 수를 구한 다음 주차료를 누적시킨다
// + 시간이 1~100까지만 주어지므로 이를 이용해도 되고...