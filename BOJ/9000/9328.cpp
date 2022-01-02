// 열쇠
// https://www.acmicpc.net/problem/9328

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cctype>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		int h, w;
		cin >> h >> w;
		vector<vector<char>> board(h, vector<char>(w));
		vector<pr> entrance;
		int documents = 0;
		int res = 0;
		queue<pr> q;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> board[i][j];
				if (board[i][j] == '$')
					documents++;
			}
		}
		vector<bool> keys(26);
		string key;
		cin >> key;
		if (key != "0")
			for (char c : key)
				keys[c - 'a'] = true;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (i == 0 || i == h - 1 || j == 0 || j == w - 1) {
					if (board[i][j] == '$') {
						res++;
						board[i][j] = '.';
					}
					if (islower(board[i][j])) {
						keys[board[i][j] - 'a'] = true;
						board[i][j] = '.';
					}
				}
			}
		}
		for (int k = 0; k < 26; k++) {
			if (!keys[k])
				continue;
			for (int i = 0; i < h; i++)
				for (int j = 0; j < w; j++)
					if (board[i][j] == 'A' + k)
						board[i][j] = '.';
		}
		for (int i = 0; i < h; i++) 
			for (int j = 0; j < w; j++) 
				if (i == 0 || i == h - 1 || j == 0 || j == w - 1) 
					if (board[i][j] != '*')
						entrance.push_back({ i, j });
		while (true) {
			if (res == documents)
				break;
			bool stop = true;
			vector<vector<bool>> visit(h, vector<bool>(w));
			for (pr p : entrance) {
				if (isupper(board[p.first][p.second]) && !keys[board[p.first][p.second] - 'A'])
					continue;
				q.push(p);
				visit[p.first][p.second] = true;
			}
			while (!q.empty()) {
				int x = q.front().first;
				int y = q.front().second;
				q.pop();
				for (int i = 0; i < 4; i++) {
					int xx = x + dx[i];
					int yy = y + dy[i];
					if (xx < 0 || yy < 0 || xx >= h || yy >= w || board[xx][yy] == '*')
						continue;
					if (!visit[xx][yy]) {
						visit[xx][yy] = true;
						if (board[xx][yy] == '$') {
							board[xx][yy] = '.';
							res++;
						}
						else if (islower(board[xx][yy])) {
							keys[board[xx][yy] - 'a'] = true;
							board[xx][yy] = '.';
							stop = false;
						}
						else if (isupper(board[xx][yy]))
							continue;
						q.push({ xx, yy });
					}
				}
			}
			if (stop)
				break;
			for (int k = 0; k < 26; k++) {
				if (!keys[k])
					continue;
				for (int i = 0; i < h; i++)
					for (int j = 0; j < w; j++)
						if (board[i][j] == 'A' + k)
							board[i][j] = '.';
			}
		}
		cout << res << '\n';
	}
}

// 각 알파벳에 대응하는 열쇠와 자물쇠가 있는 h*w 공간에서 가져갈 수 있는 문서($)의 최대 개수는?
// 건물 출입은 반드시 건물 외벽부의 입구(잠겨있을 수도 있음)(들)에서 해야 하고, 일부 자물쇠를 이미 가지고 있을 수도 있음

// bfs 탐색 문제 - 열쇠와 문서 현황에 주의해야 함
// 먼저 보드를 받고, 전체 문서의 개수를 세어준다 - 문서를 모두 모은 경우 탐색 중단
// 이후 열쇠 현황 정보를 받고, 가진 열쇠 현황을 나타내는 배열에 체크해준다
// 보드 경계로만 드나들 수 있음 - 그리고 보드 경계에도 어떤 것이든(열쇠, 문, 문서 등) 있을 수 있음
// 따라서 보드 경계를 순회하며 지금 주울 수 있는 것들은 주워서 지우기 - 문서를 주울 경우 결과값에 추가, 열쇠를 주울 경우 열쇠 현황 갱신
// 이후 지금까지 확보한 열쇠를 바탕으로 전체 보드에서 지울 수 있는 문들을 모두 지우기 ... (a)
// 그리고 건물 입구 배열을 만든 후, 보드 경계를 순회하며 벽이 아니라면 해당 배열에 삽입 - 전처리 과정에서 경계에 벽/문/빈칸만 있음이 보장된 상태

// bfs 탐색은 while(true) 안에서 진행 - 열쇠 추가 획득 시 보드를 갱신하고 새롭게 bfs를 돌려야 함
// bfs에 들어가기 전 입구 배열의 원소들을 모두 큐에 삽입해주고, visit도 갱신해주기
// 이후 bfs를 돌리는데, 접근한 곳에 문서가 있으면 줍고 빈칸으로 만들기
// 접근한 곳에 열쇠가 있으면 열쇠를 줍고 빈칸으로 만든 뒤 열쇠 현황 갱신 - 그리고 열쇠 추가 획득 플래그를 세워 bfs 탐색이 최종 종료되지 않게 설정
// 접근한 곳에 문이 있다면 그냥 지나치기 - 문을 여는 과정은 나중에 한 번에 진행
// 이렇게 bfs 탐색을 마치고 추가 열쇠를 얻었다면 (a)의 과정을 진행, 문을 빈칸으로 만든다
// 이 과정을 추가 열쇠가 나오지 않거나 모든 문서를 모을 때까지 반복 후, 결과 출력하기

// 경계에 무엇이든 있을 수 있고, 보드를 글로벌로 갱신하면 다시 처음(또는 그에 준하는 곳)부터 bfs를 돌려야 함에 주의
// 여기서 조금 더 코드를 간략화할 수도 있을듯 - 비트마스킹은 어디서?