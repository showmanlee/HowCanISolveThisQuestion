// Boggle
// https://www.acmicpc.net/problem/9202

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int dx[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int dy[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };

string dict[300001];
bool visit_w[300001];
int w;
char board[5][5];
bool visit_b[5][5];
int score;
int len;
string fword;
int found;

void dfs(int x, int y, int s, int cnt) {
	if (cnt == dict[s].length()) {
		if (visit_w[s])
			return;
		visit_w[s] = true;
		if (cnt == 3 || cnt == 4)
			score += 1;
		else if (cnt == 5)
			score += 2;
		else if (cnt == 6)
			score += 3;
		else if (cnt == 7)
			score += 5;
		else if (cnt == 8)
			score += 11;
		if (cnt > len) {
			fword = dict[s];
			len = cnt;
		}
		found++;
		return;
	}
	for (int i = 0; i < 8; i++) {
		int xx = x + dx[i];
		int yy = y + dy[i];
		if (xx < 0 || yy < 0 || xx >= 4 || yy >= 4)
			continue;
		if (!visit_b[xx][yy] && dict[s][cnt] == board[xx][yy]) {
			visit_b[xx][yy] = true;
			dfs(xx, yy, s, cnt + 1);
			visit_b[xx][yy] = false;
		}
	}
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> w;
	for (int i = 0; i < w; i++)
		cin >> dict[i];
	sort(dict, dict + w);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				cin >> board[i][j];
		for (int i = 0; i < w; i++)
			visit_w[i] = false;
		score = 0;
		found = 0;
		len = 0;
		fword = "";
		for (int s = 0; s < w; s++) {
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					if (board[i][j] == dict[s][0] && !visit_w[s]) {
						visit_b[i][j] = true;
						dfs(i, j, s, 1);
						visit_b[i][j] = false;
					}
				}
			}
		}
		cout << score << ' ' << fword << ' ' << found << '\n';
	}
}

// 4*4 보드에서 가로/세로/대각선으로 이어지는 영단어를 찾아 점수를 얻는 boggle 게임에서 단어사전과 보드가 주어졌을 때, 얻을 수 있는 최대 점수와 가장 긴 단어(사전 순 우선), 찾을 수 있는 단어 수 구하기

// 8글자까지 있는 30만 단어를 전부 탐색해봐야 하는 대형 브포 문제 - 다행히 제한 시간을 10초로 아주 많이 줌
// 일단 단어사전을 받고, '사전 순으로 가장 긴 글자를 출력'을 쉽게 하기 위해 사전에 정렬 수행
// 이후 보드를 받고, 전역 변수로 선언되어 있는 단어 방문 표시, 찾은 단어 수, 점수, 가장 긴 단어와 그 길이를 초기화 - 매 테케 시작할 때마다 초기화
// 이제 각 단어에 대해 dfs로 해당 단어가 있는지 확인 - '사전 순으로 가장 긴 글자를 출력'하기 위해서는 단어를 1차 for로 잡아줘야 함에 주의
// dfs 과정으로 해당 단어가 있음이 확인되면 해당 단어의 등장을 체크한 후, 조건에 따라 점수를 더하고 찾은 단어 개수를 추가해준 후 긴 단어를 경우에 따라 갱신한다