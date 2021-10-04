// 끝나지 않는 파티
// https://www.acmicpc.net/problem/11265

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> board(n + 1, vector<int>(n + 1));
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= n; j++) 
			cin >> board[i][j];
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (board[i][j] > board[i][k] + board[k][j])
					board[i][j] = board[i][k] + board[k][j];
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		cout << (board[a][b] <= c ? "Enjoy other party" : "Stay here") << '\n';
	}
}

// 한 파티장에서 다른 파티장으로 가는 일방통행 거리가 주어졌을 때, 특정 시간 안에 한 파티장에서 다른 파티장으로 이동할 수 있는지 판정하기

// 주어진 거리들은 최단거리가 아니기에 플로이드를 돌려 최단거리로 만들어준다
// 이후 쿼리가 주어졌을 때 주어진 시간이 구한 최단거리 이하라면 가도 된다고, 아니면 안 된다고 출력하기