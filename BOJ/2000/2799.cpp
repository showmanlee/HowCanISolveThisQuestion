// 블라인드
// https://www.acmicpc.net/problem/2799

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<vector<char>> board(n * 5 + 1, vector<char>(m * 5 + 1));
	for (int i = 0; i < n * 5 + 1; i++) {
		for (int j = 0; j < m * 5 + 1; j++) {
			cin >> board[i][j];
		}
	}
	vector<int> res(5);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			bool checked = false;
			int jj = 5 * j + 1;
			for (int t = 4; t >= 1; t--) {
				int ii = 5 * i + t;
				if (board[ii][jj] == '*') {
					res[t]++;
					checked = true;
					break;
				}
			}
			if (!checked) {
				res[0]++;
			}
		}
	}
	for (int i = 0; i < 5; i++) {
		cout << res[i] << ' ';
	}
	cout << '\n';
}

// 각 칸마다 4*4 창문이 뚫린 아파트에서 블라인드가 0/1/2/3/4칸 닫힌 상태로 주어질 때, 각 상태의 블라인드 수 구하기

// 블라인드 상태는 세로 길이에 따라서만 결정되므로 창문 전체를 볼 필요 없이 한 줄만 봐도 됨
// 따라서 창문의 대표 좌표를 정해두고, 거기서부터 맨 아래부터 닫혀있는지 확인, 닫혀있는 곳을 발견하면 해당 부분만큼 닫힌 거고, 아니면 다 열린 거고