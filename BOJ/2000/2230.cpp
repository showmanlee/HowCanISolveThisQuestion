// 수 고르기
// https://www.acmicpc.net/problem/2230

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<int> board(n);
	for (int i = 0; i < n; i++)
		cin >> board[i];
	sort(board.begin(), board.end());
	int i = 0, j = 0;
	int res = 2100000000;
	while (i < n && j < n) {
		if (board[j] - board[i] >= m) {
			res = min(res, board[j] - board[i]);
			i++;
		}
		else
			j++;
	}
	cout << res << '\n';
}

// 길이가 n인 수열에서 두 수의 차가 m 이상이면서 가장 작은 경우의 차는?
// 10만개니까 n^2로는 불가능 - 투 포인터를 이용해 복잡도를 최소화할 수 있음
// 배열을 정렬한 후, 두 포인터 변수를 처음 지점으로 초기화한다.
// 이후 조건에 따라 앞(i), 뒤(j) 포인터를 조작하며 뒤 포인터가 끝점에 도달하면 종료
// 여기서는 조건(board[j] - board[i] >= m)이 충족되면 앞 포인터를 늘려 차를 줄이고, 그렇지 않다면 뒤 포인터를 늘려 차를 늘린다