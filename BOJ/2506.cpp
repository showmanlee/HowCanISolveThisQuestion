// 점수계산
// https://www.acmicpc.net/problem/2506

#include <iostream>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int res = 0, combo = 0;
	for (int i = 0; i < n; i++) {
		int p;
		cin >> p;
		if (p == 1) {
			combo++;
			res += combo;
		}
		else
			combo = 0;
	}
	cout << res << '\n';
}

// 문제를 연속으로 맞추면 얻는 점수가 1점씩 늘어날 때, 얻는 점수는?
// 연속으로 맞추면(전 문제를 맞췄는데 또 맞췄다면) 콤보 변수를 누적시키고, 그렇지 않으면 초기화한다
// 정확히는 콤보 변수를 0으로 초기화한 후, 문제를 맞추면 누적하고, 틀리면 다시 초기화한다