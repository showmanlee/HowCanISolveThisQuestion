// 주사위 게임
// https://www.acmicpc.net/problem/5566

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int n, m;
	cin >> n >> m;
	vector<int> board(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> board[i];
	int pos = 1;
	for (int i = 1; i <= m; i++) {
		int p;
		cin >> p;
		pos += p;
		pos += board[pos];
		if (pos >= n) {
			cout << i << '\n';
			break;
		}
	}
}

// 일렬로 칸이 나열된 게임판에는 해당 칸에 도착 시 x칸 앞/뒤로 이동하라는 지시가 있을 수 있다. 주사위를 굴린 횟수와 그렇게 나온 주사위 눈 수가 주어졌을 때, 몇 번 만에 게임판 끝까지 갈 수 있는가?
// 매 턴마다 이동 후 결승점(n)을 넘어섰다면 출력 후 종료