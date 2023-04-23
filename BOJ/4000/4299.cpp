// AFC 윔블던
// https://www.acmicpc.net/problem/4299

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a, b;
	cin >> a >> b;
	int x = (a + b) / 2;
	int y = (a - b) / 2;
	if (a < b) {
		cout << -1 << '\n';
	} else {
		if (x + y == a && x - y == b) {
			cout << x << ' ' << y << '\n';
		} else {
			cout << -1 << '\n';
		}
	}
}

// 두 팀이 얻은 점수의 합과 차가 주어졌을 때, 최종 점수 구하기

// (합+차) / 2, (합-차) / 2를 구한 뒤, 이 값들의 합과 차가 주어진 합과 차와 같다면 정답