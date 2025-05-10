// DOM
// https://www.acmicpc.net/problem/10552

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, p;
	cin >> n >> m >> p;
	vector<int> board(m + 1, -1);
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		if (board[b] == -1) {
			board[b] = a;
		}
	}
	vector<bool> visit(m + 1);
	int res = 0;
	while (true) {
		if (board[p] == -1) {
			break;
		} else if (visit[p]) {
			res = -1;
			break;
		}
		visit[p] = true;
		p = board[p];
		res++;
	}
	cout << res << '\n';
}

// m칸의 보드에서 한 칸에서 다른 칸으로 가는 방향의 우선순위가 주어질 때, 이동마다 가장 높은 우선순위로만 움직여서 멈추게 ㅚ는 이동 횟수 구하기