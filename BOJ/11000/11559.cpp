// Puyo Puyo
// https://www.acmicpc.net/problem/11559

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void cascade(vector<vector<char>>& board) {
	for (int i = 0; i < 6; i++) {
		queue<char> q;
		for (int j = 0; j < 12; j++)
			if (board[j][i] != '.')
				q.push(board[j][i]);
		for (int j = 0; j < 12; j++) {
			if (!q.empty()) {
				board[j][i] = q.front();
				q.pop();
			}
			else
				board[j][i] = '.';
		}
	}
}

int finder(vector<vector<char>>& board, vector<vector<bool>>& visit, int x, int y) {
	int ret = 1;
	visit[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int xx = x + dx[i];
		int yy = y + dy[i];
		if (xx < 0 || yy < 0 || xx >= 12 || yy >= 6)
			continue;
		if (!visit[xx][yy] && board[x][y] == board[xx][yy])
			ret += finder(board, visit, xx, yy);
	}
	return ret;
}

void remover(vector<vector<char>>& board, int x, int y) {
	char key = board[x][y];
	queue<int> qx, qy;
	qx.push(x);
	qy.push(y);
	while (!qx.empty()) {
		int tx = qx.front();
		int ty = qy.front();
		board[tx][ty] = '.';
		qx.pop();
		qy.pop();
		for (int i = 0; i < 4; i++) {
			int xx = tx + dx[i];
			int yy = ty + dy[i];
			if (xx < 0 || yy < 0 || xx >= 12 || yy >= 6)
				continue;
			if (board[xx][yy] == key) {
				qx.push(xx);
				qy.push(yy);
			}
		}
	}
}

int main(void) {
	vector<vector<char>> board(12, vector<char>(6));
	for (int i = 11; i >= 0; i--) {
		string s;
		cin >> s;
		for (int j = 0; j < 6; j++)
			board[i][j] = s[j];
	}

	int res = 0;
	while (true) {
		vector<vector<bool>> visit(12, vector<bool>(6));
		vector<int> ox, oy;
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				if (board[i][j] == '.')
					visit[i][j] = true;
				else if (finder(board, visit, i, j) >= 4) {
					ox.push_back(i);
					oy.push_back(j);
				}
			}
		}
		if (ox.empty())
			break;
		for (int i = 0; i < ox.size(); i++)
			remover(board, ox[i], oy[i]);
		cascade(board);
		res++;
	}
	cout << res << '\n';
}

// 뿌요뿌요 연쇄 과정 구현하며 연쇄 수 구하기
// 떨어지는 효과를 직관적으로 하기 위해 실제 저장은 뒤집어서
// 갯수 구할 때는 DFS, 지울 때는 BFS