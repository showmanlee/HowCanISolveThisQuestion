// 지뢰 찾기
// https://www.acmicpc.net/problem/1996

#include <iostream>
#include <vector>
using namespace std;
int dx[8] = { 1, 1, 1, 0, -1, -1, -1, 0 };
int dy[8] = { 1, 0, -1, -1, -1, 0, 1, 1 };

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<vector<int>> board(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			char c;
			cin >> c;
			if (c != '.') {
				board[i][j] = -1;
				for (int k = 0; k < 8; k++) {
					int xx = i + dx[k];
					int yy = j + dy[k];
					if (xx < 0 || yy < 0 || xx >= n || yy >= n)
						continue;
					if (board[xx][yy] != -1)
						board[xx][yy] += c - '0';
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == -1)
				cout << '*';
			else if (board[i][j] > 9)
				cout << 'M';
			else
				cout << board[i][j];
		}
		cout << '\n';
	}
}

// 한 칸에 여러 개의 지뢰가 들어갈 수 있는 지뢰찾기 판의 지뢰 설치 현황이 주어졌을 때, 빈 칸에 적힌 숫자 출력하기
// 보드를 먼저 받은 후 지뢰가 담긴 칸을 제외한 나머지 칸에 대해 지뢰 총합을 구하기보다는, 지뢰 입력 과정에서부터 주변 칸에 현재 지뢰 개수를 기록하면 더 경제적일 것
// 그래서 실제로 그렇게 구현했습니다
