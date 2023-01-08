// 세 친구
// https://www.acmicpc.net/problem/17089

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<vector<bool>> board(n + 1, vector<bool>(n + 1));
	vector<int> count(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		board[a][b] = board[b][a] = true;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (board[i][j]) {
				count[i]++;
				count[j]++;
			}
		}
	}
	int res = 987654321;
	for (int a = 1; a <= n; a++) {
		for (int b = a + 1; b <= n; b++) {
			if (board[a][b]) {
				for (int c = b + 1; c <= n; c++) {
					if (board[a][c] && board[b][c]) {
						res = min(res, count[a] + count[b] + count[c] - 6);
					}
				}
			}
		}
	}
	if (res == 987654321) {
		res = -1;
	}
	cout << res << '\n';
}
 
// 친구 네트워크가 주어질 때, 모두가 서로 친구인 3명을 고를 때 선택된 사람들을 제외한 세 사람의 친구의 합이 최소가 되는 경우는?

// '친구의 수'는 그 사람과 바로 연결된 경우만 보면 됨 - dfs/bfs로 단계를 따질 필요가 없음
// 또한 친구의 '수'만 보면 됨 - 친구가 중복되더라도 무시한다
// 따라서 각자의 친구 수는 미리 구해둘 수 있음 n이 4000까지 주어지므로, 미리 n^2를 돌려 각각의 친구 수를 구해준다
// 이후 세 사람이 친구인 경우를 찾아 세 사람의 친구 합 - 6 중 최소인 경우를 찾는다 - 그런 경우가 없으면 -1 출력