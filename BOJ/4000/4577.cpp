// 소코반
// https://www.acmicpc.net/problem/4577

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int num = 1;
	while (true) {
		int r, c;
		cin >> r >> c;
		if (r == 0 && c == 0)
			break;
		vector<pr> objective;
		vector<vector<char>> board(r, vector<char>(c));
		int px = 0, py = 0;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				cin >> board[i][j];
				if (board[i][j] == '+' || board[i][j] == 'B' || board[i][j] == 'W') {
					objective.push_back({ i, j });
					if (board[i][j] == 'B')
						board[i][j] = 'b';
					if (board[i][j] == 'W')
						board[i][j] = 'w';
					if (board[i][j] == '+')
						board[i][j] = '.';
				}
				if (board[i][j] == 'w') {
					px = i;
					py = j;
				}
			}
		}
		string command;
		cin >> command;
		bool complete = false;
		for (char com : command) {
			int d = 0;
			if (com == 'U')
				d = 0;
			else if (com == 'R')
				d = 1;
			else if (com == 'D')
				d = 2;
			else if (com == 'L')
				d = 3;
			int fx = px + dx[d], fy = py + dy[d];
			int ffx = fx + dx[d], ffy = fy + dy[d];
			if (board[fx][fy] == '.') {
				swap(board[fx][fy], board[px][py]);
				px = fx;
				py = fy;
			}
			else if (board[fx][fy] == 'b' && board[ffx][ffy] == '.') {
				swap(board[fx][fy], board[ffx][ffy]);
				swap(board[fx][fy], board[px][py]);
				px = fx;
				py = fy;
			}
			bool pass = true;
			for (pr p : objective) {
				if (board[p.first][p.second] != 'b')
					pass = false;
			}
			if (pass) {
				complete = true;
				break;
			}
		}
		for (pr p : objective) {
			if (board[p.first][p.second] == '.')
				board[p.first][p.second] = '+';
			if (board[p.first][p.second] == 'w')
				board[p.first][p.second] = 'W';
			if (board[p.first][p.second] == 'b')
				board[p.first][p.second] = 'B';
		}
		cout << "Game " << num << ": " << (complete ? "complete" : "incomplete") << '\n';
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++)
				cout << board[i][j];
			cout << '\n';
		}
		num++;
	}
}

// 소코반(푸시푸시) 보드 및 조작 순서가 주어질 때, 게임 성공/실패 여부 및 조작 후 상태 출력하기
// 소코반 - 모든 상자를 목표점으로 올려놓는 게임
// 캐릭터는 상자를 밀 수 있지만, 미려는 상자 앞에 벽이나 다른 상자가 있으면 밀지 못한다
// 밀기 과정은 swap으로 구현 - 내 위치 앞에 빈 칸이면 이동, 내 위치 앞에 상자가 있는데 상자 앞이 빈칸이면 상자와 함께 이동
// 목표점과 상자/캐릭터는 겹칠 수 있음 - 입력 과정에서 목표점의 좌표만 따로 저장한 뒤, 이동 과정에서는 일반적인 칸으로 치환
// 매 이동이 끝날 때마다 목표점 좌표를 저장하고, 목표점 좌표들에 모두 상자가 있는 경우 성공 판정
// 결과 판정 후 목표점을 다시 보드에 그린 다음 출력하기