// 톱니바퀴
// https://www.acmicpc.net/problem/14891

#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> pr;

pr rotate(pr p, int d) {
	d = -d;
	p.first = (p.first + d + 8) % 8;
	p.second = (p.second + d + 8) % 8;
	return p;
}

void comm(vector<vector<char>> gear, vector<pr>& cursor, int s, int e, int d, int def) {
	if (e <= 0 || e > 4)
		return;
	if (s < e) {
		if (gear[s][def] != gear[e][cursor[e].second]) {
			int defn = cursor[e].first;
			cursor[e] = rotate(cursor[e], -d);
			comm(gear, cursor, e, e + 1, -d, defn);
		}
	}
	else {
		if (gear[s][def] != gear[e][cursor[e].first]) {
			int defn = cursor[e].second;
			cursor[e] = rotate(cursor[e], -d);
			comm(gear, cursor, e, e - 1, -d, defn);
		}
	}
}

int main(void) {
	vector<vector<char>> gear(5, vector<char>(8));
	for (int i = 1; i <= 4; i++)
		for (int j = 0; j < 8; j++)
			cin >> gear[i][j];
	vector<pr> cursor(5, { 2, 6 });
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int s, d;
		cin >> s >> d;
		int def2 = cursor[s].first;
		int def6 = cursor[s].second;
		cursor[s] = rotate(cursor[s], d);
		comm(gear, cursor, s, s + 1, d, def2);
		comm(gear, cursor, s, s - 1, d, def6);
	}
	int res = 0;
	for (int i = 1; i <= 4; i++) {
		int c = gear[i][(cursor[i].first + 6) % 8] - '0';
		res += c << (i - 1);
	}
	cout << res << '\n';
}

// 일렬로 놓인 톱니마다 자성이 있는 4개의 톱니바퀴 중 하나를 골라 회전시키는 것을 반복할 때, 마지막 상태는?
// 맞닿아있는 톱니(n번 바퀴의 2번 톱니 - n+1번 바퀴의 6번 톱니)가 돌아가기 직전 극이 다를 경우 서로 반대방향으로 회전하고, 극이 같으면 회전하지 않는다
// 톱니 전체를 돌리지 않고, 맞닿아있는 톱니 부분(초기는 2, 6번)을 기억하여 그 부분만 돌리기(회전으로 주어지는 숫자와 실제 회전 방향이 반대임에 주의)
// 돌리는 부분은 재귀함수로 구현하되, 중복 회전을 막기 위해 재귀함수 돌입 전에 회전, 회전 전 맞닿아있던 부분을 따로 빼서 인수로 전달