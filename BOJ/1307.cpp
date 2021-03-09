// 마방진
// https://www.acmicpc.net/problem/1307

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

void odd(vector<vector<int>>& board, int n, int y, int x, int c) {
	int yy = y;
	int xx = x + (n / 2);
	int count = c;
	for (int i = 1; i <= n * n; i++) {
		board[yy][xx] = count + i;
		if (i % n == 0) {
			yy++;
			if (yy >= y + n)
				yy = y;
		}
		else {
			yy--;
			xx++;
			if (yy < y)
				yy = y + n - 1;
			if (xx >= x + n)
				xx = x;
		}
	}
}

void even(vector<vector<int>>& board, int n) {
	int inc = 1;
	int dec = n * n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (abs(i - j) % 4 == 0 || (i + j + 1) % 4 == 0)
				board[j][i] = dec;
			else
				board[j][i] = inc;
			inc++;
			dec--;
		}
	}
}

void even2(vector<vector<int>>& board, int n) {
	int di[4] = { 0, 1, 0, 1 };
	int dj[4] = { 0, 1, 1, 0 };
	int h = n / 2;
	int q = h / 2;
	for (int i = 0; i < 4; i++)
		odd(board, h, di[i] * h, dj[i] * h, h * h * i);
	for (int i = 0; i < q; i++) {
		for (int j = 0; j < h; j++)
			swap(board[j][i], board[j + h][i]);
	}
	for (int i = h + q + 2; i < n; i++) {
		for (int j = 0; j < h; j++)
			swap(board[j][i], board[j + h][i]);
	}
	swap(board[q][0], board[q + h][0]);
	swap(board[q][q], board[q + h][q]);
}

int main(void) {
	int n;
	cin >> n;
	vector<vector<int>> board(n, vector<int>(n));

	if (n % 2 == 1)
		odd(board, n, 0, 0, 0);
	else if (n % 4 == 0)
		even(board, n);
	else
		even2(board, n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << board[i][j] << ' ';
		cout << '\n';
	}
}

// 주어진 크기의 마방진 만들기
// 학부 자구 시간에 배웠는데, 마방진을 만드는 공식은 3가지가 있다
// 1. n % 2 == 1인 경우
//   1부터 차례대로 [0][n / 2]부터 우측 상단 방향으로 올라가면서 숫자를 채운다.
//   커서가 배열에서 벗어나는 경우, 즉 상단을 벗어나면 제일 하단으로, 우측으로 벗어나면 좌측으로 이동한다.
//   카운트가 count % n == 0이 되는 경우, 우측 상단이 아닌 하단으로 한칸 이동한다.
// 2. n % 4 == 0인 경우
//   좌측 상단부터 순서대로 숫자를 채운다.
//   단, [i][j]가 (i + j + 1) % 4 == 0 또는 (abs(i - j)) % 4 == 0인 경우 해당 자리의 역순 숫자를 채운다.
// 3. 그 외의 경우
//   1 3
//   4 2
//   위와 같은 방식으로 배열을 4등분하여 각 조각에 삽입되는 숫자를 조정한 'n % 2 == 1인 경우' 마방진을 채운다.
//   이후 좌측 조각들의 왼쪽에서 절반만큼의 세로줄을 swap하고, 우측 조각들의 오른쪽에서 절반 - 1만큼의 세로줄을 swap한다.
//   마지막으로 [1/4][0]과 [3/4][0], [1/4][1/4]와 [3/4][1/4]에 있는 값을 swap한다.
// 어떻게 보면 복습입니다