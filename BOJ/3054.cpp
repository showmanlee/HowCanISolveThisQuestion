// 피터팬 프레임
// https://www.acmicpc.net/problem/3054

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string s;
	cin >> s;
	vector<vector<char>> board(5, vector<char>(s.length() * 4 + 1, '.'));
	for (int i = 0; i < s.length(); i++) {
		if (i % 3 != 2) {
			int x = 2, y = i * 4 + 2;
			board[x][y] = s[i];
			board[x - 2][y] = board[x + 2][y] = board[x][y + 2] = board[x][y - 2] = '#';
			board[x - 1][y - 1] = board[x - 1][y + 1] = board[x + 1][y + 1] = board[x + 1][y - 1] = '#';
		}
	}
	for (int i = 0; i < s.length(); i++) {
		if (i % 3 == 2) {
			int x = 2, y = i * 4 + 2;
			board[x][y] = s[i];
			board[x - 2][y] = board[x + 2][y] = board[x][y + 2] = board[x][y - 2] = '*';
			board[x - 1][y - 1] = board[x - 1][y + 1] = board[x + 1][y + 1] = board[x + 1][y - 1] = '*';
		}
	}
	for (vector<char> v : board) {
		for (char c : v)
			cout << c;
		cout << '\n';
	}
}

// 대문자로 구성된 문자열 중 매 3번째 문자는 마름모 모양 *로 둘러싸인 웬디 프레임, 마름모 모양 #로 둘러싸인 피터팬 프레임으로 장식한 결과 출력하기

// 보드를 배열 형태로 그리고 출력하기
// 웬디 프레임이 피터팬보다 우선임에 주의 - 웬디 프레임을 피터팬 프레임을 그린 이후 그리기