// 나의 인생에는 수학과 함께
// https://www.acmicpc.net/problem/17265

#include <iostream>
#include <vector>
#include <cctype>
#include <algorithm>
using namespace std;

char board[6][6];
bool visit[6][6];
int n, maxx, minn;

void dfs(int x, int y, int cur, char prev) {
	visit[x][y] = true;
	if (isdigit(board[x][y])) {
		if (prev == ' ')
			cur += board[x][y] - '0';
		else if (prev == '+')
			cur += board[x][y] - '0';
		else if (prev == '-')
			cur -= board[x][y] - '0';
		else if (prev == '*')
			cur *= board[x][y] - '0';
	}
	if (x == n - 1 && y == n - 1) {
		maxx = max(maxx, cur);
		minn = min(minn, cur);
		return;
	}
	int xx = x + 1;
	int yy = y + 1;
	if (xx < n) 
		dfs(xx, y, cur, board[x][y]);
	if (yy < n)
		dfs(x, yy, cur, board[x][y]);
	visit[x][y] = false;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> board[i][j];
	maxx = -987654321;
	minn = 987654321;
	dfs(0, 0, 0, ' ');
	cout << maxx << ' ' << minn << '\n';
}


// 숫자와 연산자가 격자처럼 놓여있는 n*n 보드의 좌측 상단에서 우측 하단으로 이동하면서 만나는 숫자와 연산자를 순서대로 연산할 때, 얻을 수 있는 최댓값과 최솟값 출력하기

// dfs 백트래킹 기반 - 움직일 수 있는 방향은 우측과 하단 뿐
// 보드 입력을 받고, 최댓값과 최솟값 초기값 할당 후 좌측 상단에서 탐색 시작
// dfs 함수는 좌표값, 현재까지의 연산값, 그리고 직전 문자를 매개변수로 받음 - 이동 방향이 겹치지 않도록 정해져 있으므로 visit는 의미가 없음(그런데 무의식적으로 붙였음)
// 만약 이번에 밟은 곳이 숫자 칸이라면 지난 문자(연산자)를 기준으로 연산값에 연산해주기 - 첫 칸인 경우 그냥 숫자 더하기
// 이렇게 도착점까지 이동하면 최종 연산값으로 최댓값과 최솟값 갱신