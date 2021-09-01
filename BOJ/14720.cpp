// 우유 축제
// https://www.acmicpc.net/problem/14720

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int cur = 0, res = 0;
	for (int i = 0; i < n; i++) {
		int p;
		cin >> p;
		if (p == cur) {
			res++;
			cur = (cur + 1) % 3;
		}
	}
	cout << res << '\n';
}

// 일렬로 놓인 상점들은 각각 0, 1, 2 우유 중 하나만 팔고 있고, 좌측에서 우측으로 이동하면서 0, 1, 2, 0... 순서대로 우유를 먹을 수 있을 때, 최대로 먹을 수 있는 우유의 개수는?

// 현재 먹어야 할 우유를 나타내는 변수, 그리고 누적되는 결과값을 준비하기
// 이후 숫자를 입력받으며 현재 상점의 우유가 먹어야 할 우유와 같으면 결과값은 1 올리고, 먹어야 할 우유는 순환시키기
// 이렇게 모두 돌린 후 나온 결과값이 답