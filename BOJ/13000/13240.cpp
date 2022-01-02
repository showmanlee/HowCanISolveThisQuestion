// Chessboard
// https://www.acmicpc.net/problem/13240

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << (i % 2 == j % 2 ? '*' : '.');
		}
		cout << '\n';
	}
}


// n*m 체스판 그리기(좌측 상단이 칠해져 있음)

// 조금 생각해서 그리면 됩니다