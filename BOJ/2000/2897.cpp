// 몬스터 트럭
// https://www.acmicpc.net/problem/2897

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<vector<char>> board(n, vector<char>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	vector<int> res(5);
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m - 1; j++) {
			int p = 0;
			p += (board[i][j] == 'X' ? 1 : 0);
			p += (board[i][j + 1] == 'X' ? 1 : 0);
			p += (board[i + 1][j] == 'X' ? 1 : 0);
			p += (board[i + 1][j + 1] == 'X' ? 1 : 0);
			if (board[i][j] == '#' || board[i][j + 1] == '#' || board[i + 1][j] == '#' || board[i + 1][j + 1] == '#') {
				continue;
			}
			res[p]++;
		}
	}
	for (int i = 0; i < 5; i++) {
		cout << res[i] << '\n';
	}
}

// n*m 공간에서 2*2 크기의 몬스터 트럭이 빌딩 말고 일반 차를 부수고 주차할 수 있을 때, 주차 공간 수를 부서야 하는 차 개수별로 출력하기

// 보드를 받고, 각 2*2 영역에 대해 일반 차의 개수를 센 뒤, 그 과정에서 빌딩이 나오지 않았다면 해당되는 결과값에 누적한다
// 그렇게 끝까지 봐야 함