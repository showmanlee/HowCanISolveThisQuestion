// 서버실
// https://www.acmicpc.net/problem/17245

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int left = 0, right = 0;
	long long sum = 0;
	vector<vector<int>> board(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			sum += board[i][j];
			right = max(right, board[i][j]);
		}
	}
	int res = 0;
	long long target = sum / 2;
	if (sum % 2 == 1)
		target += 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		long long s = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				s += min(board[i][j], mid);
		if (s >= target) {
			res = mid;
			right = mid - 1;
		}
		else
			left = mid + 1;
	}
	cout << left << '\n';
}

// 각 칸에 서로 다른 수의 서버가 쌓여있는 n*n 공간에서 서버가 바닥에 설치한 1분에 1칸씩 올라오는 냉방기의 냉기를 받아야 작동할 때, 공간 내 모든 서버의 절반 이상을 작동시키기 위해 필요한 냉방기의 최소 작동 시간은?

// 한 칸에 1000만 대의 서버가 있을 수 있음 - 이분 탐색으로 봐야 함
// 100만 칸에 각 1000만 대의 서버가 있을 수 있음 - 서버 수의 총합은 long long으로 계산하기
// 성공 조건이 절반 이상이기에 서버 수 합이 홀수일 경우 절반(.5 버림)에서 +1을 해줘야 함
// 어쨌든 보드를 받으며 서버의 총합을 구하면서 이분 탐색 right 값(서버의 최댓값)도 함께 구해두기
// 이후 이분 탐색을 돌리는데, 모든 칸의 min(mid, 서버 수)의 합이 서버 수의 절반 이상이라면 결과값을 mid로 두고 right 당기기, 그렇지 않다면 left 당기기
// 그러다가 left와 right가 교차되는 순간 결과값이 답