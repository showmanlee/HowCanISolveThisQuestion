// 제곱수 찾기
// https://www.acmicpc.net/problem/1025

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<vector<char>> board(n, vector<char>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	int res = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int x = -n; x <= n; x++) {
				for (int y = -m; y <= m; y++) {
					if (x == 0 && y == 0) {
						continue;
					}
					int a = i, b = j;
					int p = 0;
					while (a >= 0 && a < n && b >= 0 && b < m) {
						p *= 10;
						p += board[a][b] - '0';
						int pp = (int)sqrt(p);
						if (pp * pp == p) {
							res = max(res, p);
						}
						a += x;
						b += y;
					}
				}
			}
		}
	}
	cout << res << '\n';
}

// 각 칸에 숫자가 적힌 n*m 보드에서 행의 번호가 선택한 순서대로 등차수열을 이루고 있어야 하고, 열의 번호도 선택한 순서대로 등차수열을 이루도록 수를 선택해 이어붙여 만들 수 있는 완전제곱수 중 가장 큰 수는?

// 즉, 보드에서 직선을 그어서 고를 수 있는 수를 모두 고른다고 생각하면 됨 - 방향 제한 없고, 길이 제한도 없음
// 보드 시작 위치, 그리고 x/y 기울기를 정한 후, 하나씩 숫자를 붙여가며 완전제곱수를 판정해본다
// 완전제곱수 판정 방식은 sqrt(p)를 int로 바꾼 후, 그 수의 제곱이 원래 수와 동일한지 확인하는 것 - 소수점 계산할 필요 없이
// n^4, n^5 연산이 되긴 하지만 보드 최대 크기가 9라서 문제없음 - 당연히 int 범위도 만족하고