// 마술사 이민혁
// https://www.acmicpc.net/problem/3023

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int r, c;
	cin >> r >> c;
	vector<vector<char>> piece(r, vector<char>(c));
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> piece[i][j];
		}
	}
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < r * 2; i++) {
		for (int j = 0; j < c * 2; j++) {
			int a = (i < r ? i : r - (i - r) - 1);
			int b = (j < c ? j : c - (j - c) - 1);
			if (i == n - 1 && j == m - 1) {
				cout << (piece[a][b] == '#' ? '.' : '#');
			} else {
				cout << piece[a][b];
			}
		}
		cout << '\n';
	}
}

// 카드 배경의 .과 #으로 구성된 좌측 상단 패턴을 받은 뒤 특정 좌표의 문자를 반대로 적으려 할 때, 결과 출력하기

// 조각 받아서 점대칭으로 그려주면서, 에러 좌표에서는 반대로 출력하기
// 조금 복잡한 출력 문제