// 정육면체 전개도
// https://www.acmicpc.net/problem/1917

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	for (int t = 0; t < 3; t++) {
		vector<vector<int>> board(6, vector<int>(6));
		vector<int> count_x(6), count_y(6);
		for (int i = 0; i < 6; i++)
			for (int j = 0; j < 6; j++)
				cin >> board[i][j];

		bool flag = false;
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 6; j++) {
				if (board[i][j] == 1)
					count_x[i]++;
				else if (board[i][j] == 0 && count_x[i] != 0)
					break;
			}
			for (int j = 0; j < 6; j++) {
				if (board[j][i] == 1)
					count_y[i]++;
				else if (board[j][i] == 0 && count_y[i] != 0)
					break;
			}
		}
		int sum_x = 0, sum_y = 0;
		int sx = -1, sy = -1, gx = -1, gy = -1;
		for (int i = 0; i < 6; i++) {
			sum_x += count_x[i];
			sum_y += count_y[i];
			if (sx == -1 && count_x[i] != 0)
				sx = i;
			if (sy == -1 && count_y[i] != 0)
				sy = i;
			if (sx != -1 && count_x[i] == 0 && gx == -1)
				gx = i;
			if (sy != -1 && count_y[i] == 0 && gy == -1)
				gy = i;
		}
		if (gx == -1)
			gx = 6;
		if (gy == -1)
			gy = 6;
		if (sum_x != 6 || sum_y != 6) {
			cout << "no\n";
			continue;
		}
		bool res = true;
		if (gx - sx == 5 && gy - sy == 2) {
			if (count_y[sy] != count_y[sy + 1])
				res = false;
			if (count_x[sx + 2] != 2)
				res = false;
		}
		else if (gx - sx == 2 && gy - sy == 5) {
			if (count_x[sx] != count_x[sx + 1])
				res = false;
			if (count_y[sy + 2] != 2)
				res = false;
		}
		else if (gx - sx == 4 && gy - sy == 3) {
			if (count_y[sy + 1] == 4) {
				vector<int> cnt(4);
				for (int i = sx; i < gx; i++)
					cnt[count_x[i]]++;
				if (!((cnt[3] == 1 && cnt[1] == 3) || (cnt[2] == 2 && cnt[1] == 2)))
					res = false;
			}
			else if (count_y[sy + 1] == 3) {
				if (count_x[sx] != 1 && count_x[sx + 3] != 1)
					res = false;
			}
			else if (count_y[sy + 1] == 2) {
				if (count_y[sy] != 2 || count_y[sy + 2] != 2)
					res = false;
				if (count_x[sx] != 1 || count_x[sx + 1] != 2 || count_x[sx + 2] != 2 || count_x[sx + 3] != 1)
					res = false;
			}
			else
				res = false;
		}
		else if (gx - sx == 3 && gy - sy == 4) {
			if (count_x[sx + 1] == 4) {
				vector<int> cnt(4);
				for (int i = sy; i < gy; i++)
					cnt[count_y[i]]++;
				if (!((cnt[3] == 1 && cnt[1] == 3) || (cnt[2] == 2 && cnt[1] == 2)))
					res = false;
			}
			else if (count_x[sx + 1] == 3) {
				if (count_y[sy] != 1 && count_y[sy + 3] != 1)
					res = false;
			}
			else if (count_x[sx + 1] == 2) {
				if (count_x[sx] != 2 || count_x[sx + 2] != 2)
					res = false;
				if (count_y[sy] != 1 || count_y[sy + 1] != 2 || count_y[sy + 2] != 2 || count_y[sy + 3] != 1)
					res = false;
			}
			else
				res = false;
		}
		else
			res = false;
		cout << (res ? "yes" : "no") << '\n';
	}
}

// 6*6 보드에 정육면체 전개도가 주어졌을 때, 유효한지 판단하기

// 일단 입력 상으로 6개의 1은 모두 붙어있는 것이 보장됨
// 유효한 정육면체 전개도의 형태는 11가지(회전 제외)
// 1           1           1           1     1           1
// 1 1 1 1   1 1 1 1   1 1 1 1   1 1 1 1   1 1 1 1   1 1 1 1  ...(1)
// 1         1         1         1           1         1
//     1 1       1 1       1 1
// 1 1 1     1 1 1     1 1 1                                  ...(2)
// 1           1           1
//     1 1
//   1 1         1 1 1                                        ...(3), (4)
// 1 1       1 1 1
// 이 형태를 4가지로 분류할 수 있다
// - 4개의 1에 위아래로 1이 붙어있는 경우(1)
// - 2개의 1과 3개의 1이 모서리에 붙어있고, 아래에 1이 붙어있는 경우(2)
// - 2개의 1이 서로 계단형을 이루는 경우(3)
// - 3개의 1이 서로 계단형을 이루는 경우(4)
// 물론 모든 경우를 직접 찍어서 bfs나 브포로 다룰 수도 있으나, 일반화를 해보자

// 우선 각 행/열의 연속으로 등장한 1이 나오는 횟수를 구하고, 그 횟수들을 더해본다
// 만약 각 축에서 등장한 연속된 1의 합이 6개가 아닌 경우 무조건 에러
// 그러면서 각 축에서 1이 처음으로 등장한 좌표와 사라진 좌표를 기록한다
// 이제 두 좌표의 차가 전개도의 크기가 된다
// 가능한 전개도 크기의 경우의 수는 4가지 - 2*5, 3*4, 4*3, 5*2
// 만약 2*5/5*2인 경우 짧은쪽의 연속된 1이 3/3인 경우면서 긴쪽의 연속된 일이 1/1/2/1/1인 경우에만 가능
// 3*4/4*3인 경우 다음 경우에만 가능
// - 짧은쪽의 연속된 1이 1/4/1이고, 긴쪽의 연속된 1의 개수가 1x3/3x1 or 1x2/2x2인 경우
// - 짧은쪽의 연속된 1이 2/3/1 or 1/3/2이고, 긴쪽의 연속된 1 중 양끝 중 하나가 1인 경우
// - 짧은쪽의 연속된 1이 2/2/2이고, 긴쪽의 연속된 1이 1/2/2/1인 경우
// 전개도 크기를 이미 확인했고 전개도의 1이 모두 이어져있음이 보장되기 때문에 조건문의 수가 많지는 않음 