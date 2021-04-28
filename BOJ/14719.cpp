// 빗물
// https://www.acmicpc.net/problem/14719

#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> board(n, vector<int>(m));
	for (int i = 0; i < m; i++) {
		int p;
		cin >> p;
		for (int j = n - 1; j >= 0; j--) {
			board[j][i] = (p > 0 ? 1 : 2);
			p--;
		}
	}
	for (int i = 0; i < n; i++) {
		if (board[i][0] == 2) {
			int p = 0;
			while (p < m && board[i][p] == 2) {
				board[i][p] = 0;
				p++;
			}
		}
		if (board[i][m - 1] == 2) {
			int p = m - 1;
			while (p >= 0 && board[i][p] == 2) {
				board[i][p] = 0;
				p--;
			}
		}
	}
	int res = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (board[i][j] == 2)
				res++;
	cout << res << '\n';
}

// 주어진 지형에 비가 아주 많이 왔을 때, 고이는 비의 양은?

// 지형 끝이 비어있으면 고이지 않는다 - 하지만 바닥은 상관없이 고인다
// 따라서 빗물 고임 여부를 확인하기 위해서는 지형 양 끝쪽만 보고 처리하면 된다
// 입력받은 지형 높이를 토대로 2차원 배열에 지형을 그리는데, 지형(1)이 없는 쪽에는 우선 모두 빗물(2)로 채운다
// 이후 위에서부터 점점 내려오면서, 양 끝쪽에 빗물이 있는지(= 양 끝에 벽이 없는지) 확인한다
// 만약 양 끝에 벽이 없다면 해당 지점에서 반대쪽으로 가면서 벽이 나올 때까지 해당 위치들에 있던 빗물을 모두 없앤다
// 이 과정을 마친 후 2차원 배열에 남은 빗물 수를 세서 출력