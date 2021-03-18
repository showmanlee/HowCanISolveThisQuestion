// 백조의 호수
// https://www.acmicpc.net/problem/3197

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int r, c;
	cin >> r >> c;
	int xs = -1, ys = -1, xe = -1, ye = -1;
	vector<vector<char>> board(r, vector<char>(c));
	queue<pr> waters;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'L') {
				if (xs != -1) {
					xe = i;
					ye = j;
				}
				else {
					xs = i;
					ys = j;
				}
			}
			if (board[i][j] == 'L' || board[i][j] == '.')
				waters.push({ i, j });
		}
	}
	vector<vector<bool>> visit(r, vector<bool>(c));
	queue<pr> q;
	q.push({ xs, ys });
	visit[xs][ys] = true;
	int day = 0;
	while (true) {
		queue<pr> nq;
		bool flag = false;
		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			if (x == xe && y == ye) {
				flag = true;
				break;
			}
			for (int i = 0; i < 4; i++) {
				int xx = x + dx[i];
				int yy = y + dy[i];
				if (xx < 0 || yy < 0 || xx >= r || yy >= c)
					continue;
				if (!visit[xx][yy]) {
					visit[xx][yy] = true;
					if (board[xx][yy] != 'X') 
						q.push({ xx, yy });
					else
						nq.push({ xx, yy });
				}
			}
		}
		if (flag)
			break;
		int size = waters.size();
		for (int t = 0; t < size; t++) {
			int x = waters.front().first;
			int y = waters.front().second;
			waters.pop();
			for (int i = 0; i < 4; i++) {
				int xx = x + dx[i];
				int yy = y + dy[i];
				if (xx < 0 || yy < 0 || xx >= r || yy >= c)
					continue;
				if (board[xx][yy] == 'X') {
					board[xx][yy] = '.';
					waters.push({ xx, yy });
				}
			}
		}
		q = nq;
		day++;
	}
	cout << day << '\n';
}

// 두 백조가 빙판 때문에 서로 만날 수 없다. 하루에 한 칸씩 얼음이 녹을 때, 두 백조가 만나는 날은?

// 최대 1500*1500이라 무식하게 BFS를 돌렸다가는 시간 초과 가능성 다분
// 얼음을 녹이면서 출발점부터 도착점까지 도달할 수 있는지 확인
// 둘 다 움직일 필요는 없음 - 어차피 '언제' 만나느냐가 중요하지 언제 '어떻게' 만나는 게 중요하지는 않음
// 얼음 녹이기 시뮬레이션 - (새로운 아이디어) 물을 따로 저장하는 큐를 만들기
// 도착점 도달에 실패하면 현재 큐의 사이즈까지만 큐를 돌리며 주변의 얼음을 녹이고 큐에 삽입하기
// 큐의 특성 상 그 날의 얼음을 다 녹이면 다음날 얼음이 준비됨
// 이 과정이 끝나면 하루 보내기

// 하지만 이렇게 해도 시간 초과가 난다면 모든 날 통틀어 보드 탐색을 한 번만 하도록 설계할 수도 있음
// visit와 q를 모든 날에서 공용으로 사용하도록 설정하고, 대신 하루 탐색 중 만나는 얼음을 매 날마다 사용하는 예비 큐에 삽입한다
// 이후 날이 바뀌기 전에 예비 큐를 공용 큐로 바꿔주기(단순 대입, '버퍼 큐') - 다음 날에 '이어서' 탐색할 수 있도록
// 다시 말하지만 '어떻게' 만나느냐가 아닌 '언제' 만나느냐가 중요한 문제이기 때문에 '이어서' 탐색해도 문제가 없음

// BOJ 500문제 돌파!
// 골드를 넘어 플레로 가자