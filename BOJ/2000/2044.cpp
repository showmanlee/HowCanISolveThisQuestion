// windows
// https://www.acmicpc.net/problem/2044

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;

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
	vector<vector<bool>> visit(n, vector<bool>(m));
	vector<string> roster;
	map<string, pr> sizes;
	map<string, string> titler;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visit[i][j]) {
				visit[i][j] = true;
				if (board[i][j] == '+') {
					string name;
					string title = "+";
					int x = 1, y = 1;
					for (int k = j + 1; k < m; k++) {
						title += board[i][k];
						y++;
						if (board[i][k] == '+') {
							break;
						}
						if (board[i][k] >= 'a' && board[i][k] <= 'z')
							name += board[i][k];
					}
					for (int k = i + 1; k < n; k++) {
						x++;
						if (board[k][j] == '+') {
							break;
						}
					}
					roster.push_back(name);
					sizes[name] = { x, y };
					titler[name] = title;
					for (int k = i; k < i + x; k++) {
						for (int l = j; l < j + y; l++) {
							visit[k][l] = true;
						}
					}
				}
			}
		}
	}
	sort(roster.begin(), roster.end());
	vector<vector<char>> res(n, vector<char>(m, '.'));
	int idx = 0;
	for (string name : roster) {
		int x = sizes[name].first;
		int y = sizes[name].second;
		string title = titler[name];
		for (int j = idx; j < idx + y; j++) {
			res[idx][j] = title[j - idx];
		}
		for (int i = idx + 1; i < idx + x; i++) {
			for (int j = idx; j < idx + y; j++) {
				if (i == idx + x - 1) {
					res[i][j] = '-';
				}
				if (j == idx || j == idx + y - 1) {
					res[i][j] = '|';
				}
				if ((i == idx + x - 1) && (j == idx || j == idx + y - 1)) {
					res[i][j] = '+';
				}
			}
		}
		for (int i = idx + 1; i < idx + x - 1; i++) {
			for (int j = idx + 1; j < idx + y - 1; j++) {
				res[i][j] = '.';
			}
		}
		idx++;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << res[i][j];
		}
		cout << '\n';
	}
}

// n*m 화면 안에 이름이 다른 창들이 겹치지 않고 나열되어 있을 때, 이를 사전 순서대로 크기 변경 없이 계단식으로 배치하기

// 창이 겹치지 않았기 때문에 보드 1회 탐색으로도 모든 창의 이름과 크기를 알 수 있음
// 방문하지 않은 픽셀을 차례대로 탐색하다가 +를 발견한 경우 해당 지점에서 창 크기 탐색
// 우측으로 뻗어 +가 닿으면 가로 길이, 하단으로 뻗어 +가 닿으면 세로 길이
// 가로 길이를 잴 때 창 이름도 같이 얻을 수 있음 - 창을 배치할 때 - 정렬이 귀찮으므로 아예 창 상단을 통째로 저장해두자
// 길이를 쟀다면 해당 범위 내의 픽셀을 모두 방문했다고 표시, 중복 탐색이 없도록 함
// 이후 얻은 이름들을 정렬하고, (0, 0)부터 차례대로 정렬된 창을 뿌린다
// 아래부터 하나씩 창을 뿌리고, 창 내부를 모두 .로 채워서 밑에 있는 창이 보이지 않도록 한다