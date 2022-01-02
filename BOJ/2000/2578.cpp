// 빙고
// https://www.acmicpc.net/problem/2578

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int board[5][5];
	int call[25];
	bool mark[5][5];
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++) {
			cin >> board[i][j];
			mark[i][j] = false;
		}
	for (int i = 0; i < 25; i++)
		cin >> call[i];

	for (int t = 0; t < 25; t++) {
		int score = 0;
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 5; j++)
				if (call[t] == board[i][j])
					mark[i][j] = true;
		
		for (int i = 0; i < 5; i++) {
			if (mark[i][0] && mark[i][1] && mark[i][2] && mark[i][3] && mark[i][4])
				score++;
			if (mark[0][i] && mark[1][i] && mark[2][i] && mark[3][i] && mark[4][i])
				score++;
		}
		if (mark[0][0] && mark[1][1] && mark[2][2] && mark[3][3] && mark[4][4])
			score++;
		if (mark[0][4] && mark[1][3] && mark[2][2] && mark[3][1] && mark[4][0])
			score++;

		if (score >= 3) {
			cout << t + 1 << endl;
			break;
		}
	}
}