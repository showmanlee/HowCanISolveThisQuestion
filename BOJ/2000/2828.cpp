// 사과 담기 게임
// https://www.acmicpc.net/problem/2828

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, j;
	cin >> n >> m >> j;
	vector<int> apples(j);
	for (int i = 0; i < j; i++)
		cin >> apples[i];
	int res = 0, pos = 1;
	for (int i = 0; i < j; i++) {
		if (pos > apples[i]) {
			res += pos - apples[i];
			pos = apples[i];
		}
		else if (pos + m <= apples[i]) {
			res += apples[i] - pos - m + 1;
			pos = apples[i] - m + 1;
		}
	}
	cout << res << '\n';
}

// n칸의 화면에서 떨어지는 사과를 m칸의 바구니로 받는 게임을 할 때, 사과를 모두 받을 수 있게 하는 최소 이동 횟수는?
// 바구니의 범위는 [pos, pos + m)으로 볼 수 있음
// 만약 사과가 pos 보다 작은 곳에 떨어지거나, pos + m 이상인 곳에 떨어지면 바구니 끝점이 닿을 수 있게 움직이면 됨
// 굳이 바구니를 중간 지점에 맞출 필요는 없음 - 중간 지점에 사과들이 쏟아져도 결국 끝점에 따라 움직이게 되어있음