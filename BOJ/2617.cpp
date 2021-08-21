// 구슬 찾기
// https://www.acmicpc.net/problem/2617

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
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		board[a][b] = 1;
		board[b][a] = -1;
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (board[i][k] == board[k][j] && board[i][j] == 0)
					board[i][j] = board[i][k];
			}
		}
	}
	int res = 0;
	for (int i = 1; i <= n; i++) {
		int plus = 0, minus = 0;
		for (int j = 1; j <= n; j++) {
			if (board[i][j] == 1)
				plus++;
			else if (board[i][j] == -1)
				minus++;
		}
		if (plus > n / 2 || minus > n / 2)
			res++;
	}
	cout << res << '\n';
}

// 구슬 n개(홀수) 중 일부의 무게 관계가 주어졌을 때, 무게 순으로 나열할 때 절대 중간으로 올 수 없는 구슬은?

// 자신보다 무거운/가벼운 구슬이 절반 넘게 있을 경우 그 구슬은 가운데로 올 수 없음
// 대소관계를 확장할 때 플로이드를 활용할 수 있음 - 만약 i-k와 k-j 관계가 동일하고, i-j 관계가 정의되지 않았을 때  i-k/k-j 관계가 i-j 관계가 됨
// 따라서 플로이드로 주어진 대소관계를 확장시켜 갱신한 후, 각 구슬마다 등장한 대소관계의 수를 세 절반 넘게 나온 대소관계가 있다면 결과값에 누적
// 그리고 그렇게 누적된 결과값을 출력하기