// 호석이 두 마리 치킨
// https://www.acmicpc.net/problem/21278

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int n, m;
	cin >> n >> m;
	vector<vector<int>> board(n + 1, vector<int>(n + 1, 987654321));
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		board[a][b] = 1;
		board[b][a] = 1;
	}
	for (int i = 1; i <= n; i++)
		board[i][i] = 0;
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (board[i][j] > board[i][k] + board[k][j])
					board[i][j] = board[i][k] + board[k][j];
			}
		}
	}
	int resa = -1, resb = -1, resl = 987654321;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			int p = 0;
			for (int k = 1; k <= n; k++)
				p += min(board[i][k], board[k][j]) * 2;
			if (resl > p) {
				resa = i;
				resb = j;
				resl = p;
			}
		}
	}
	cout << resa << ' ' << resb << ' ' << resl << '\n';
}

// n개의 건물이 m개의 도로로 이어져 있는 도시에서 건물 2개의 치킨집을 놓을 때, 어떤 건물과 가장 가까운 치킨집의 왕복 거리의 합이 최소가 되도록 놓는 방법과 그 합은?

// 두 곳에 건물을 놓아 최단거리 만들기 - 가중치 없는 플로이드를 활용하면 모든 건물간의 최단거리를 구할 수 있음
// 가중치가 없는 플로이드 - 최초 간선이 1, [i][i]가 0인 2차원 배열에서 시작해 플로이드를 돌린다
// 이후 두 개의 건물을 골라 해당 건물들과 나머지 건물 간의 최소 왕복 거리의 합을 구한 뒤, 이 값에 따라 결과값을 갱신해주기
// n이 100까지이므로 n^3를 여러 번 돌려도 부담이 없음