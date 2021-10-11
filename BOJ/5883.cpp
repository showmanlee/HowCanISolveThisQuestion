// 아이폰 9S
// https://www.acmicpc.net/problem/5883

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> board(n + 1);
	set<int> candi;
	board[0] = -1;
	for (int i = 1; i <= n; i++) {
		cin >> board[i];
		candi.insert(board[i]);
	}
	int res = 0;
	for (int p : candi) {
		int combo = 1;
		int prev = board[0];
		for (int i = 1; i <= n; i++) {
			if (board[i] == p) {
				continue;
			}
			if (prev == board[i]) {
				combo++;
			}
			else {
				combo = 1;
			}
			res = max(res, combo);
			prev = board[i];
		}
	}
	cout << res << '\n';
}

// 줄을 서 있는 사람들이 원하는 용량들이 주어질 때, 어떤 용량을 원하는 사람 전체를 줄에서 빼서 얻을 수 있는 같은 용량을 원하는 사람이 연속된 길이 중 최댓값은?

// 줄 길이가 1000이므로 브루트포스로 접근 가능
// 줄 입력을 받으며 등장한 용량을 추린 후, 나온 용량 중 하나를 줄에서 배제하며 연속된 길이 측정
// 길이 측정은 '이전 사람'이 가진 용량과 현재 사람이 가진 용량을 비교하며 같다면 길이를 늘리는 방식으로 진행 - '이전 사람'은 이전에 탐색을 진행한 사람v