// 눈 치우기
// https://www.acmicpc.net/problem/26215

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
	for (int i = 0; i < n; i++) {
		cin >> board[i];
	}
	int res = 0;
	while (true) {
		if (res > 1440) {
			break;
		}
		sort(board.begin(), board.end(), greater<int>());
		if (board[0] == 0) {
			break;
		}
		if (board[1] != 0) {
			res += board[1];
			board[0] -= board[1];
			board[1] = 0;
		} else {
			res += board[0];
			board[0] = 0;
			break;
		}
	}
	if (res > 1440) {
		res = -1;
	}
	cout << res << '\n';
}
 
// 각 집 앞에 쌓인 눈의 양이 주어지고, 1분에 1개 또는 2개의 집 눈을 1만큼 치울 수 있을 때 모든 집의 눈을 치우는데 걸리는 최소 시간은?

// 1분마다 집들 중 가장 많이 쌓인 집 2개를 찾아서 그 중 덜 쌓인 만큼의 눈을 더 쌓인 곳까지 같이 치운다
// 이후 남은 눈이 한 곳 밖에 없다면 거기를 끝까지 치운다
// 그렇게 얻은 값이 1440 초과면 아웃
// 매번 정렬해도 괜찮음 - 집 수는 최대 100, 한 번 돌릴 때마다 최소 하나의 집은 사라지는 게 보장되므로