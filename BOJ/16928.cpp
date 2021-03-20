// 뱀과 사다리 게임
// https://www.acmicpc.net/problem/16928

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(void) {
	vector<int> board(101);
	for (int i = 1; i <= 100; i++)
		board[i] = i;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n + m; i++) {
		int a, b;
		cin >> a >> b;
		board[a] = b;
	}
	vector<int> visit(101, -1);
	queue<int> q;
	q.push(1);
	visit[1] = 0;
	while (!q.empty()) {
		int p = q.front();
		q.pop();
		if (p == 100)
			break;
		for (int i = 1; i <= 6; i++) {
			if (p + i > 100)
				continue;
			int pp = board[p + i];
			if (visit[pp] == -1) {
				visit[pp] = visit[p] + 1;
				q.push(pp);
			}
		}
	}
	cout << visit[100] << '\n';
}

// 100칸 보드에 뱀과 사다리가 그려진 뱀과 사다리 게임에서 주사위를 굴려 1번 칸에서 100번 칸으로 이동하는 최소 거리는?
// BFS인데 이동 방식이 주사위인 것
// 해당 칸에 도착하면 최종적으로 도착하는 칸을 저장하는 배열을 만들기 - 디폴트는 board[i] = i, 뱀/사다리가 있는 경우 board[i] != i
// 따라서 이동 판정은 board 안에서 진행하기 - 물론 이동한 칸이 100을 넘어서면 패스
// "1번 칸과 100번 칸은 뱀과 사다리의 시작 또는 끝이 아니다." = 100번 칸 이후로 넘어가도 100번 칸에 간 걸로 간주하지 않는다는 의미(후진은 안 하므로 1번은 그냥 시작점)
// 100번 칸 이후에는 뱀/사다리가 없음이 보장되므로, 100번 칸 이후로 가면 다시는 100번 칸으로 돌아올 수 없음 - 따라서 패스