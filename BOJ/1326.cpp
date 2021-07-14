// 폴짝폴짝
// https://www.acmicpc.net/problem/1326

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> board(n + 1), visit(n + 1, -1);
	for (int i = 1; i <= n; i++)
		cin >> board[i];
	int s, d;
	cin >> s >> d;
	queue<int> q;
	q.push(s);
	visit[s] = 0;
	while (!q.empty()) {
		int p = q.front();
		q.pop();
		if (p == d)
			break;
		for (int i = -n; i <= n; i++) {
			int pp = p + board[p] * i;
			if (pp <= 0 || pp > n)
				continue;
			if (visit[pp] == -1) {
				visit[pp] = visit[p] + 1;
				q.push(pp);
			}
		}
	}
	cout << visit[d] << '\n';
}

// 각 칸에 숫자가 적힌 1차원 보드에서 칸에 적힌 수의 배수만큼 이동할 수 있을 때, 출발지에도 도착지까지 가는 최소 이동 횟수는?

// 일반적인 bfs - 이동 범위는 칸에 적힌 숫자의 배수
// 이동 범위는 기본적으로 -n~n으로 설정 - 어떤 상황에서도 해당 범위를 벗어나지는 않음
// 만약 벗어나게 되면 continue로 처리하기