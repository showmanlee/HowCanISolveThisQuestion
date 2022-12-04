// 세 수 고르기
// https://www.acmicpc.net/problem/1503

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<bool> board(1001);
	for (int i = 0; i < m; i++) {
		int p;
		cin >> p;
		board[p] = true;
	}
	int res = 1987654321;
	for (int i = 1; i <= 1001; i++) {
		if (board[i]) {
			continue;
		}
		for (int j = i; j <= 1001; j++) {
			if (board[j]) {
				continue;
			}
			for (int k = j; k <= 1001; k++) {
				if (board[k]) {
					continue;
				}
				res = min(res, abs(n - (i * j * k)));
			}
		}
	}
	cout << res << '\n';
}

// 자연수 n과 m개의 자연수 풀이 주어질 때, 자연수 풀을 제외한 나머지 자연수 3개를 고를 떄 | n - xyz |의 최솟값 구하기

// 자연수 x, y, z는 서로 중복될 수 있음 - 풀만 중복되지 않을 뿐 고르는 건 같아도 됨
// xyz의 범위가 언급되지는 않았지만, n의 범위가 1000까지이므로 xyz의 범위도 1000까지가 되어야 함
// 다만 반례가 있음 - 999, 1000을 사용할 수 없는 상황일 때 |1000 - 1001|을 만들어야 하는 경우가 있을 수 있음
// 따라서 최대 범위는 1~1001로 두고 계산한다 - 경우의 수는 10억이지만 단순 정수 계산이므로 브루트포스로 처리 가능