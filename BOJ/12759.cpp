// 틱! 택! 토!
// https://www.acmicpc.net/problem/12759

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int player;
	cin >> player;
	vector<vector<int>> board(4, vector<int>(4));
	for (int i = 1; i <= 3; i++)
		for (int j = 1; j <= 3; j++)
			board[i][j] = (i * 10) * (j * 2);
	for (int i = 0; i < 9; i++) {
		int x, y;
		cin >> x >> y;
		board[x][y] = player;
		if ((board[x][1] == board[x][2] && board[x][2] == board[x][3]) ||
			(board[1][y] == board[2][y] && board[2][y] == board[3][y]) ||
			(board[1][1] == board[2][2] && board[2][2] == board[3][3]) ||
			(board[1][3] == board[2][2] && board[2][2] == board[3][1])) {
			cout << player << '\n';
			return 0;
		}
		player = (player == 1 ? 2 : 1);
	}
	cout << 0 << '\n';
	return 0;
}

// 선공을 정하고 시작하는 틱택토를 돌리며 누가 승자인지 판정하기
// 입력을 받으며 보드에 숫자를 쓰다가, 승자가 결정나는 타이밍이 되면 출력하기
// 조건문 간소화(?)를 위해 보드에는 1/2 이외의 임의의 수를 채워넣음 - 다른 수로 인해 동일 판정이 나지 않게
// 승자가 결정되는 순간 return해야 함에 주의