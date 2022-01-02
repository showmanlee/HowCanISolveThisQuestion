// 누울 자리를 찾아라
// https://www.acmicpc.net/problem/1652

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<vector<char>> board(n, vector<char>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> board[i][j];
	int resv = 0, resh = 0;
	for (int i = 0; i < n; i++) {
		int combo = 0;
		bool exist = false;
		for (int j = 0; j < n; j++) {
			if (board[i][j] == '.')
				combo++;
			else
				combo = 0;
			if (!exist && combo == 2)
				resh++;
			if (combo >= 2)
				exist = true;
			else
				exist = false;
		}
		combo = 0;
		exist = false;
		for (int j = 0; j < n; j++) {
			if (board[j][i] == '.')
				combo++;
			else
				combo = 0;
			if (!exist && combo == 2)
				resv++;
			if (combo >= 2)
				exist = true;
			else
				exist = false;
		}
	}
	cout << resh << ' ' << resv << '\n';
}

// n*n 보드에서 연속으로 두 칸 이상 등장하는 빈칸 개수 세기

// 보드를 받고, 각 축에서 연속으로 등장하는 빈칸 개수 세주기
// 한 줄에서도 여러 개의 결과가 나올 수 있기에, 지금 보는 빈칸들이 이미 체크되었다는 exist 변수 활용하기
// 만약 연속 빈칸이 2개가 된 경우, 먼저 결과값을 누적해준 뒤 exist 체크
// 빈칸이 끝난 경우 exist 언체크