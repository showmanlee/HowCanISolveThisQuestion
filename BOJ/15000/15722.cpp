// 빙글빙글 스네일
// https://www.acmicpc.net/problem/15722

#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int x = 0, y = 0;
	int cnt = 1, max = 1;
	bool dir = true, mode = true;
	for (int i = 1; i <= n; i++) {
		if (!mode) {
			x += dir ? 1 : -1;
		} else {
			y += dir ? 1 : -1;
		}
		cnt--;
		if (cnt == 0) {
			mode = !mode;
			if (mode) {
				dir = !dir;
				max++;
			}
			cnt = max;
		}
	}
	cout << x << ' ' << y << '\n';
}

// 원점에서 출발해 1초에 1칸씩 나선형으로 움직이는 점의 특정 시간에서의 위치 구하기

// y + 1, x + 1, y - 2, x - 2... 이 순으로 반복됩니다
// 이를 잘 계산해서 위치 출력하기