// 우유가 넘어지면?
// https://www.acmicpc.net/problem/17363

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
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];
	for (int i = m - 1; i >= 0; i--) {
		for (int j = 0; j < n; j++) {
			if (board[j][i] == '-')
				cout << '|';
			else if (board[j][i] == '|')
				cout << '-';
			else if (board[j][i] == '/')
				cout << '\\';
			else if (board[j][i] == '\\')
				cout << '/';
			else if (board[j][i] == '^')
				cout << '<';
			else if (board[j][i] == '<')
				cout << 'v';
			else if (board[j][i] == 'v')
				cout << '>';
			else if (board[j][i] == '>')
				cout << '^';
			else
				cout << board[j][i];
		}
		cout << '\n';
	}
}

// 보드에 적힌 문자들을 왼쪽으로 돌려 출력하기

// 왼쪽으로 90도 돌려 출력하면서, 바뀌는 문자들은 조건에 따라 바꿔서 출력하기