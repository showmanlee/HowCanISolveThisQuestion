// 숫자 카드
// https://www.acmicpc.net/problem/10815

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> board(n);
	for (int i = 0; i < n; i++)
		cin >> board[i];
	sort(board.begin(), board.end());
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int p;
		cin >> p;
		cout << (*lower_bound(board.begin(), board.end(), p) == p) << ' ';
	}
}

// 현재 가지고 있는 숫자카드들 중 선택한 숫자들이 있나요?
// 숫자카드 범위가 +-1천만, 카드의 수는 50만, 쿼리의 수도 50만
// 대놓고 이분탐색 쓰라고 만든 문제
// 받은 숫자카드들을 정렬한 후, lower_bound를 돌려 해당 위치의 수가 찾는 숫자라면 1 표시