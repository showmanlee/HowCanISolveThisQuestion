// 그림 비교
// https://www.acmicpc.net/problem/2160

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<vector<string>> board(n + 1, vector<string>(5));
	for (int t = 1; t <= n; t++) {
		for (int i = 0; i < 5; i++) {
			cin >> board[t][i];
		}
	}
	int resa = 0, resb = 0, resn = 99;
	for (int i = 1; i < n; i++) {
		for (int j = i + 1; j <= n; j++) {
			int p = 0;
			for (int x = 0; x < 5; x++) {
				for (int y = 0; y < 7; y++) {
					if (board[i][x][y] != board[j][x][y]) {
						p++;
					}
				}
			}
			if (p < resn) {
				resn = p;
				resa = i;
				resb = j;
			}
		}
 	}
	cout << resa << ' ' << resb << '\n';
}

// 5*7 보드 n개 중 같은 위치에 다른 글자가 있는 개수가 가장 적은 쌍은?

// 보드의 크기는 언제나 5*7, 결과 쌍은 단 하나임이 보장됨
// 각각의 보드를 문자열 배열로 만들고, 이후 두 개를 선택해서 다른 글자의 개수를 구한다
// 이렇게 다른 글자 개수를 구하며 가장 적은 글자를 가진 쌍이 답