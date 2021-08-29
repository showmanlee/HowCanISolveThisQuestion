// 로봇 시뮬레이션
// https://www.acmicpc.net/problem/2174

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;
typedef pair<pr, int> prr;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int dir(char d) {
	if (d == 'N')
		return 0;
	else if (d == 'E')
		return 1;
	else if (d == 'S')
		return 2;
	else if (d == 'W')
		return 3;
	return -1;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a, b, n, m;
	cin >> a >> b >> n >> m;
	vector<vector<int>> board(b + 1, vector<int>(a + 1));
	vector<prr> robots(n + 1);
	for (int i = 1; i <= n; i++) {
		int x, y;
		char d;
		cin >> y >> x >> d;
		robots[i] = { {x, y}, dir(d) };
		board[x][y] = i;
	}
	string res = "OK";
	for (int t = 0; t < m; t++) {
		int p, r;
		char d;
		cin >> p >> d >> r;
		if (res != "OK")
			continue;
		for (int i = 0; i < r; i++) {
			int x = robots[p].first.first;
			int y = robots[p].first.second;
			if (d == 'L')
				robots[p].second = (robots[p].second + 3) % 4;
			else if (d == 'R')
				robots[p].second = (robots[p].second + 1) % 4;
			else {
				int xx = x + dx[robots[p].second];
				int yy = y + dy[robots[p].second];
				if (xx <= 0 || yy <= 0 || xx > b || yy > a)
					res = "Robot " + to_string(p) + " crashes into the wall";
				else if (board[xx][yy] != 0)
					res = "Robot " + to_string(p) + " crashes into robot " + to_string(board[xx][yy]);
				else {
					robots[p].first = { xx, yy };
					board[x][y] = 0;
					board[xx][yy] = p;
				}
			}
			if (res != "OK")
				break;
		}
	}
	cout << res << '\n';
}

// a*b 공간에 n개의 로봇이 어떤 방향을 바라보고 놓여 있고, 해당 로봇들에 차례대로 명령을 줄 때 가장 먼저 일어나는 충돌은?

// 말 그대로 로봇을 직접 공간 상에 놓아보고 명령을 수행하면 됨
// 로봇의 경우 현재 위치와 방향값을 기억하도록 배열에 저장하고, 현재 로봇의 위치를 별도의 보드에도 기록하여 충돌 판정을 용이하게 설정
// 명령을 받을 때, 회전 입력의 경우 그냥 회전만 시켜주면 되지만, 전진 입력의 경우 해당 방향으로 직접 전진시켜줘야 함 - 그러면서 충돌도 발생 가능
// 따라서 다음 위치를 미리 잡은 뒤, 보드를 벗어난다면 벽과 충돌 판정, 다른 로봇이 있는 위치에 도달했다면 로봇과 충돌 판정 주기 - 아무 충돌도 없었다면 로봇 정보 및 보드에 새로운 로봇 위치 기록하기
// 충돌 판정은 결과 문자열이 초기값이자 정상값인 OK가 아님으로 판정 - OK가 아니라면 추가 명령 반복을 하지 않고, 이어지는 새 명령도 입력만 받고 처리를 하지 않음

// 방향 체계 및 입력 순서가 평소와 다름에 주의