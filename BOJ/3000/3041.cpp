// N-퍼즐
// https://www.acmicpc.net/problem/3041

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	vector<vector<char>> board(4, vector<char>(4));
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> board[i][j];
		}
	}
	int res = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (board[i][j] == '.') {
				continue;
			}
			int p = board[i][j] - 'A';
			res += abs(i - (p / 4)) + abs(j - (p % 4));
		}
	}
	cout << res << '\n';
}

// 4*4 퍼즐에서 알파벳들의 위치가 주어졌을 때, 각 알파벳의 원래 위치와 현재 위치 간 맨해튼 거리의 합 구하기

// 현재 위치 = (알파벳 순서 / 4, 알파벳 순서 % 4)
// 이를 이용해서 거리를 구해준 뒤 합쳐줍시다 