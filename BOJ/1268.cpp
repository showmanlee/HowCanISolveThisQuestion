// 임시 반장 정하기
// https://www.acmicpc.net/problem/1268

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<vector<int>> board(n + 1, vector<int>(5));
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < 5; j++)
			cin >> board[i][j];
	vector<vector<bool>> checker(n + 1, vector<bool>(n + 1));
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 5; j++) {
			for (int k = 1; k <= n; k++) {
				if (board[i][j] == board[k][j])
					checker[i][k] = true;
			}
		}
	}
	int resn = 0, resi = 0;
	for (int i = 1; i <= n; i++) {
		int res = 0;
		for (int j = 1; j <= n; j++) {
			res += checker[i][j];
		}
		if (res > resn) {
			resn = res;
			resi = i;
		}
	}
	cout << resi << '\n';
}

// 지난 1~5학년 동안 가장 많은 사람과 같은 반이 됐던 사람은?

// 학생별 반 변동 현황을 2차원 배열 형태로 저장한 후, 각 칸을 선택해 그 칸과 같은 학년 학생들을 보고 같다면 카운트를 늘린다
// 표 크기가 1000인 만큼 n^3 기반으로 접근해도 됨
// 다만 같은 반이 된 '횟수'를 기록하는 것이 아닌 '사람 수'를 기록하는 것이기에(중복 X) 카운트는 배열에 체크하는 방식으로 진행하기
// 모든 체크가 끝난 후 체크된 개수에 따라 답이 결정됨 - 동률일 경우 숫자가 작은 쪽이 우선
