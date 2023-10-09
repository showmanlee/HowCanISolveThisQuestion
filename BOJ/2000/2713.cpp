// 규현이의 사랑을 담은 문자메시지
// https://www.acmicpc.net/problem/2713

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		int r, c;
		string s;
		cin >> r >> c;
		getline(cin, s);
		vector<vector<char>> board(r + 2, vector<char>(c + 2));
		for (int i = 0; i < c + 2; i++) {
			board[0][i] = board[r + 1][i] = '-';
		}
		for (int i = 0; i < r + 2; i++) {
			board[i][0] = board[i][c + 1] = '-';
		}
		vector<char> v;
		for (int i = 1; i < s.length(); i++) {
			int p = s[i] - 'A' + 1;
			if (s[i] == ' ') {
				p = 0;
			}
			int z = 16;
			for (int j = 0; j < 5; j++) {
				int pp = p / z % 2;
				v.push_back('0' + pp);
				z /= 2;
			}
		}
		int x = 1, y = 0;
		int d = 0;
		for (int i = 0; i < r * c; i++) {
			int xx = x + dx[d];
			int yy = y + dy[d];
			if (board[xx][yy] != 0) {
				d = (d + 1) % 4;
				xx = x + dx[d];
				yy = y + dy[d];
			}
			if (i < v.size()) {
				board[xx][yy] = v[i];
			} else {
				board[xx][yy] = '0';
			}
			x = xx;
			y = yy;
		}
		for (int i = 1; i <= r; i++) {
			for (int j = 1; j <= c; j++) {
				cout << board[i][j];
			}
		}
		cout << '\n';
	}
}

// 주어진 공백 포함 대문자 문자열을 공백 = 0, 나머지는 순서로 해서 5자리 2진수로 만든 뒤 r*c 보드에 나선형으로 써넣은 걸 1차원 문자열로 출력한 결과 구하기

// 문자열에 공백이 포함되어 있으므로 cin 숫자 2개, 문자열은 getline으로 받기 - 이 경우 앞에 공백 하나 들어가니까 공백 빼줘야 함
// 그러고 2진수 배열 만들어 미리 넣어두고, 나선형 순회하면서 2진수 문자 채워주기 - 남는 공간은 '0'으로 채우기