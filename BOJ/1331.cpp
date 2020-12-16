// 나이트 투어
// https://www.acmicpc.net/problem/1331

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;
pr d[8] = { {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1} };

int main(void) {
	vector<pr> board(36);
	vector<vector<bool>> step(6, vector<bool>(6));
	for (int i = 0; i < 36; i++) {
		string s;
		cin >> s;
		board[i] = { s[0] - 'A', s[1] - '1' };
	}
	bool fail = false;
	for (int i = 0; i < 36; i++) {
		bool pass = false;
		for (int j = 0; j < 8; j++) {
			int x = d[j].first + board[i].first;
			int y = d[j].second + board[i].second;
			if (board[(36 + i - 1) % 36] == make_pair(x, y)) {
				pass = true;
				break;
			}
		}
		if (!pass) {
			fail = true;
			break;
		}
		if (step[board[i].first][board[i].second]) {
			fail = true;
			break;
		}
		step[board[i].first][board[i].second] = true;
	}
	if (fail)
		cout << "Invalid" << '\n';
	else
		cout << "Valid" << '\n';
}

// 6x6 체스판에서 나이트가 모든 칸(36)을 밟고 지나가는 경로로 가고 있는가?
// 입력이 유효한가(나이트가 갈 수 없는 곳으로 가고 있는가)? 그리고 중복되는 칸을 밟지 않고 있는가?
// 그리고 마지막 위치에서 출발점으로 돌아올 수 있는가?
// 체스판 밖으로 나가는 입력은 주어지지 않음 - 조건식 잘 세우기