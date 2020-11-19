// 스도쿠 채점
// https://www.acmicpc.net/problem/9291

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	for (int t = 1; t <= n; t++) {
		vector<vector<int>> board(9, vector<int>(9));
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++)
				cin >> board[i][j];
		}
		bool fail = false;
		for (int i = 0; i < 9; i++) {
			vector<bool> va(10), vb(10);
			for (int j = 0; j < 9; j++) {
				va[board[i][j]] = true;
				vb[board[j][i]] = true;
			}
			for (int j = 1; j <= 9; j++)
				if (!(va[j] && vb[j]))
					fail = true;
			if (fail)
				break;
		}
		for (int i = 1; i <= 3; i++) {
			for (int j = 1; j <= 3; j++) {
				vector<bool> v(10);
				for (int k = 3 * (i - 1); k < 3 * i; k++)
					for (int l = 3 * (j - 1); l < 3 * j; l++)
						v[board[k][l]] = true;
				for (int k = 1; k <= 9; k++)
					if (!v[k])
						fail = true;
				if (fail)
					break;
			}
			if (fail)
				break;
		}
		if (fail) 
			cout << "Case " << t << ": INCORRECT\n";
		else
			cout << "Case " << t << ": CORRECT\n";
	}
}

// 스도쿠 만들고 푸는 게 어렵지 채점하는 건 쉽잖아