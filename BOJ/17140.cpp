// 이차원 배열과 연산
// https://www.acmicpc.net/problem/17140

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;

int r, c, k;
int row, col;
int board[100][100];

void process_r() {
	vector<vector<pr>> sorter(row);
	int size = 0;
	for (int i = 0; i < row; i++) {
		vector<int> count(101);
		for (int j = 0; j < col; j++)
			count[board[i][j]]++;
		int s = 0;
		for (int j = 1; j <= 100; j++) {
			if (count[j] != 0) {
				sorter[i].push_back({ count[j], j });
				s++;
			}
		}
		if (size < s)
			size = s;
	}
	for (int i = 0; i < row; i++)
		sort(sorter[i].begin(), sorter[i].end());
	col = min(100, size * 2);
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < size; j++) {
			if (sorter[i].size() <= j) {
				board[i][j * 2] = board[i][j * 2 + 1] = 0;
				continue;
			}
			board[i][j * 2] = sorter[i][j].second;
			board[i][j * 2 + 1] = sorter[i][j].first;
		}
	}
}

void process_c() {
	vector<vector<pr>> sorter(col);
	int size = 0;
	for (int i = 0; i < col; i++) {
		vector<int> count(101);
		for (int j = 0; j < row; j++)
			count[board[j][i]]++;
		int s = 0;
		for (int j = 1; j <= 100; j++) {
			if (count[j] != 0) {
				sorter[i].push_back({ count[j], j });
				s++;
			}
		}
		if (size < s)
			size = s;
	}
	for (int i = 0; i < col; i++)
		sort(sorter[i].begin(), sorter[i].end());
	row = min(100, size * 2);
	for (int i = 0; i < col; i++) {
		for (int j = 0; j < size; j++) {
			if (sorter[i].size() <= j) {
				board[j * 2][i] = board[j * 2 + 1][i] = 0;
				continue;
			}
			board[j * 2][i] = sorter[i][j].second;
			board[j * 2 + 1][i] = sorter[i][j].first;
		}
	}
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	row = col = 3;
	cin >> r >> c >> k;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			cin >> board[i][j];
	int res = 0;
	while (board[r - 1][c - 1] != k && res <= 100) {
		if (row >= col)
			process_r();
		else
			process_c();
		res++;
	}
	if (res > 100)
		res = -1;
	cout << res << '\n';
}

// 주어진 3*3 배열을 매 초마다 다음과 같이 정렬할 때, 100초 안에 board[r][c] == k가 되는가? 된다면 그 시간은?
// - 만약 row >= col이라면 행을 기준으로, 그렇지 않다면 열을 기준으로 정렬을 수행한다
// - 한 (행/열)에 등장하는 모든 수(0 제외)의 등장 횟수를 세어, 그 숫자와 등장 횟수를 (등장 횟수-숫자) 순의 오름차순으로 정렬하여 [숫자, 등장횟수] 순으로 해당 (행/열)에 덮어씌운다
// - i.e) [3, 1, 1] -> [3, 1, 1, 2](3이 *1*회, 1이 *2*회) -> [2, 1, 3, 1, 1, 2](**2**가 1회, **3**이 1회, 1이 *2*회)
// - 만약 다른 (행/열)의 정렬 결과로 인해 한 (행/열)에 빈칸이 남는다면 0으로 채우고, 정렬한 (행/열)의 크기가 100을 넘어서면 그 이후의 정렬 결과는 버린다

// 설명이 요상하고 이해가 잘 안되지만 이해만 한다면 0.5초 내에 처리 가능한 연산임을 알 수 있음
// - 배열의 크기가 최대 100, 초기에 주어지는 배열 내 수의 최대가 100 - 연산 특성 상 아무리 오래 해도 100이 넘는 수가 등장할 수 없음
// 카운팅 정렬의 일종이라고도 볼 수 있지만, 등장 횟수를 기준으로 정렬해야 하기에 결과적으로 일반적인 정렬 시간복잡도가 나옴 - 가능

// 우선 각 (행/열)에 대해 숫자의 등장 횟수를 기록 - 이후 유효한 수치(숫자나 등장 횟수가 0이 아닌 경우)에 대해 정렬할 배열에 pair로 삽입
// 등장 횟수가 우선이 되어야 하므로 등장 횟수를 first로 하여 저장
// 모든 (행/열) 조사를 마치면 가장 숫자가 많이 등장한 (행/열)의 길이 * 2를 새로운 (열/행)의 길이로 삼는다
// 그리고 새롭게 정의된 크기에 맞춰 정렬 결과를 덮어씌운다
// 이 과정을 100초가 지나거나 board[r][c] == k가 될 때까지 반복