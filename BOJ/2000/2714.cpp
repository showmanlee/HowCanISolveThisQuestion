// 문자를 받은 승환이
// https://www.acmicpc.net/problem/2714

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
		cin >> r >> c >> s;
		vector<vector<char>> board(r + 2, vector<char>(c + 2, '-'));
        int idx = 0;
        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                board[i][j] = s[idx++];
            }
        }
		int x = 1, y = 0;
		int d = 0, cnt = 0;
        string buf, res;
		for (int i = 0; i < r * c; i++) {
			int xx = x + dx[d];
			int yy = y + dy[d];
			if (board[xx][yy] == '-') {
				d = (d + 1) % 4;
				xx = x + dx[d];
				yy = y + dy[d];
			}
            buf += board[xx][yy];
            board[xx][yy] = '-';
            cnt++;
            if (cnt == 5) {
                int a = 16, p = 0;
                for (int k = 0; k < 5; k++) {
                    p += (buf[k] - '0') * a;
                    a /= 2;
                }
                if (p == 0) {
                    res += ' ';
                } else {
                    res += ('A' + p - 1);
                }
                cnt = 0;
                buf = "";
            }
			x = xx;
			y = yy;
		}
        while (res.back() == ' ') {
            res.pop_back();
        }
        cout << res << '\n';
	}
}

// 2713번 문제를 통해 만든 2진수 문자열을 복호화하기

// 역으로 만들면 되긴 합니다 - 대신 후행 공백 없애는 거 잊지 마세요