// 체스판 다시 칠하기
// https://www.acmicpc.net/problem/1018

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void) {
	int n, m, min = 64;
	vector<string> board;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		board.push_back(s);
	}
	for (int p = 0; p <= n - 8; p++) 
		for (int q = 0; q <= m - 8; q++) {
			bool init = (board[p][q] == 'B');
			int count = 0;
			for (int i = 0; i < 8; i++) {
				bool tick = (i % 2 == 0 ? init : !init);
				for (int j = 0; j < 8; j++) {
					if ((tick && board[p + i][q + j] == 'W') || (!tick && board[p + i][q + j] == 'B'))
						count++;
					tick = !tick;
				}
			}
			if (count > 32)
				count = 64 - count;
			if (count < min)
				min = count;
		}
	cout << min << '\n';
}

// 이게 브루트포스
// 자른 체스판의 첫 번째 칸을 칠해서 계산하는 게 맞을 수도 있음(count > 32) - 이 경우 선택 안한 걸 선택하도록 반전