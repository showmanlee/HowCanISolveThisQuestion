// 친구
// https://www.acmicpc.net/problem/1058

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<vector<char>> board(n, vector<char>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> board[i][j];
	int res = 0;
	for (int i = 0; i < n; i++) {
		int p = 0;
		for (int j = 0; j < n; j++) {
			if (i == j)
				continue;
			if (board[i][j] == 'Y')
				p++;
			else {
				for (int k = 0; k < n; k++) {
					if (k == i || k == j)
						continue;
					if (board[i][k] == 'Y' && board[k][j] == 'Y') {
						p++;
						break;
					}
				}
			}
		}
		res = max(res, p);
	}
	cout << res << '\n';
}

// 2-친구의 정의가 두 사람이 친구거나 두 사람 사이를 잇는 친구가 있는 것일 때, 2-친구의 수가 가장 많은 사람의 2-친구 수는?

// 보드 입력에서 board[i][i] == N, board[i][j] == board[j][i]임이 보장되어 있는 상황
// 한 사람당 최대 2명까지의 다른 사람을 체크해야 하니 n^3 알고리즘으로 접근할 수 있음 - n이 50까지니 충분히 가능
// 각 사람에 대해 2-친구의 수를 세는데, 다른 사람들을 탐색하며 두 사람이 직접적으로 친구라면 친구 수를 추가하고 넘어가기
// 그렇지 않다면 다른 모든 사람에 대해 두 사람과 친구인 사람을 찾고, 그런 사람을 찾았다면 친구 수를 추가하고 넘어가기
// 이렇게 얻은 2-친구 수를 결과값에 갱신하고, 최종적으로 갱신된 결과값 출력하기