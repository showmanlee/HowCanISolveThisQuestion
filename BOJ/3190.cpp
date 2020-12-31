// 뱀
// https://www.acmicpc.net/problem/3190

#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;
typedef pair<int, char> comm;
pr d[4] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

pr operator+(pr a, pr b) {
	return { a.first + b.first, a.second + b.second };
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, k, l;
	vector<pr> apples;
	queue<comm> commands;
	deque<pr> snake;
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		apples.push_back({ a, b });
	}
	cin >> l;
	for (int i = 0; i < l; i++) {
		int a;
		char c;
		cin >> a >> c;
		commands.push({ a, c });
	}
	vector<vector<bool>> board(n + 1, vector<bool>(n + 1));
	int clock = 0, dir = 0;
	snake.push_front({ 1, 1 });
	board[1][1] = true;
	while (true) {
		clock++;
		pr p = snake.front();
		pr pp = p + d[dir];
		if (pp.first <= 0 || pp.first > n || pp.second <= 0 || pp.second > n || board[pp.first][pp.second])
			break;
		board[pp.first][pp.second] = true;
		snake.push_front(pp);
		if (find(apples.begin(), apples.end(), pp) == apples.end()) {
			board[snake.back().first][snake.back().second] = false;
			snake.pop_back();
		}
		else
			apples.erase(find(apples.begin(), apples.end(), pp));
		if (!commands.empty() && commands.front().first == clock) {
			if (commands.front().second == 'L')
				dir = (dir + 4 - 1) % 4;
			else
				dir = (dir + 1) % 4;
			commands.pop();
		}
	}
	cout << clock << '\n';
}

// 뱀 게임(Dummy)에서 판의 크기(정사각형)과 사과의 위치, 그리고 이동 명령이 주어졌을 때 게임이 언제 끝나는가?
// deque로 뱀 구현(앞 뒤 둘 다 봐야 하니까), 2차원 배열을 보드로 만들어 뱀 위치 검출
// 새로운 초 시작 -> 말 이동 및 충돌 판정 -> 방향 전환