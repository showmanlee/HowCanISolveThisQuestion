// 쿠키의 신체 측정
// https://www.acmicpc.net/problem/20125

#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> pr;

int main(void) {
	int n;
	cin >> n;
	vector<vector<char>> board(n, vector<char>(n));
	int hx = -1, hy = -1;
	int la = 0, ra = 0, w = 0, ll = 0, rl = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			if (board[i][j] == '*' && hx == -1 && hy == -1) {
				hx = i + 1;
				hy = j;
			}
		}
	}
	for (int i = hy - 1; i >= 0; i--) {
		if (board[hx][i] == '*')
			la++;
		else
			break;
	}
	for (int i = hy + 1; i < n; i++) {
		if (board[hx][i] == '*')
			ra++;
		else
			break;
	}
	for (int i = hx + 1; i < n; i++) {
		if (board[i][hy] == '*')
			w++;
		else
			break;
	}
	for (int i = hx + w + 1; i < n; i++) {
		if (board[i][hy - 1] == '*')
			ll++;
		else
			break;
	}
	for (int i = hx + w + 1; i < n; i++) {
		if (board[i][hy + 1] == '*')
			rl++;
		else
			break;
	}
	cout << (hx + 1) << ' ' << (hy + 1) << '\n' << la << ' ' << ra << ' ' << w << ' ' << ll <<  ' ' << rl << '\n';
}

// 쿠키의 심장 위치와 양쪽 팔, 허리, 양쪽 다리의 길이 출력하기
// 머리는 반드시 심장 바로 위에 한 칸 있고, 팔은 반드시 심장 양옆으로 뻗어있으며, 허리는 반드시 심장 하단으로 뻗어있고, 다리는 허리가 끝나는 지점 좌/우측 하단에서 아래로 뻗어있다
// 이 규칙을 활용해 머리-심장을 먼저 찾고, 심장 위치를 기준으로 다른 부위의 길이도 for로 찾아낸다