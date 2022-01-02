// 가희야 거기서 자는 거 아니야
// https://www.acmicpc.net/problem/21771

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int r, c, rg, cg, rp, cp;
	cin >> r >> c >> rg >> cg >> rp >> cp;
	vector<vector<char>> board(r, vector<char>(c));
	int cnt = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'P')
				cnt++;
		}
	}
	cout << (rp * cp != cnt) << '\n';
}

// r*c 보드에서 베개(P)와 가희(G)의 배치도가 주어질 때, 가희가 베개 위에서 자고 있는지 판정하기

// 일단 우리는 베개와 가희의 크기를 알고 있다 - 그리고 베개를 가릴 수 있는 건 가희 뿐
// 따라서 보드를 받으며 P의 개수를 세어준 뒤, 만약 P의 개수가 베개 크기보다 적으면 가희가 가린 것이므로 1 출력