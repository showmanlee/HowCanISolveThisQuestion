// 낚시왕
// https://www.acmicpc.net/problem/17143

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
using namespace std;
typedef pair<int, int> pr;
typedef tuple<pr, int, int, int> tppi3;
int dx[5] = { 0, -1, 1, 0, 0 };
int dy[5] = { 0, 0, 0, 1, -1 };

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int r, c, m;
	cin >> r >> c >> m;
	vector<vector<int>> board(r + 1, vector<int>(c + 1));
	vector<tppi3> sharks(m + 1);
	for (int i = 1; i <= m; i++) {
		int x, y, s, d, z;
		cin >> x >> y >> s >> d >> z;
		board[x][y] = i;
		if (d <= 2)
			s %= ((r - 1) * 2);
		else
			s %= ((c - 1) * 2);
		sharks[i] = { {x, y}, s, d, z };
	}
	vector<bool> catched(m + 1);
	int res = 0;
	for (int t = 1; t <= c; t++) {
		for (int i = 1; i <= r; i++) {
			if (board[i][t] != 0) {
				catched[board[i][t]] = true;
				res += get<3>(sharks[board[i][t]]);
				board[i][t] = 0;
				break;
			}
		}
		for (int s = 1; s <= m; s++) {
			if (catched[s])
				continue;
			int x = get<0>(sharks[s]).first;
			int y = get<0>(sharks[s]).second;
			int speed = get<1>(sharks[s]);
			int dir = get<2>(sharks[s]);
			while (speed > 0) {
				speed--;
				x += dx[dir];
				y += dy[dir];
				if (x <= 0 || y <= 0 || x > r || y > c) {
					dir += (dir % 2 == 1 ? 1 : -1);
					x += dx[dir] * 2;
					y += dy[dir] * 2;
				}
			}
			get<0>(sharks[s]) = { x, y };
			get<2>(sharks[s]) = dir;
		}
		for (int i = 1; i <= r; i++)
			for (int j = 1; j <= c; j++)
				board[i][j] = 0;

		for (int s = 1; s <= m; s++) {
			if (catched[s])
				continue;
			int cur = board[get<0>(sharks[s]).first][get<0>(sharks[s]).second];
			if (cur != 0) {
				if (get<3>(sharks[s]) > get<3>(sharks[cur])) {
					board[get<0>(sharks[s]).first][get<0>(sharks[s]).second] = s;
					catched[cur] = true;
				}
				else
					catched[s] = true;
			}
			else
				board[get<0>(sharks[s]).first][get<0>(sharks[s]).second] = s;
		}
	}
	cout << res << '\n';
}

// 상어가 m마리 있는 r*c 수조에서 다음과 같은 과정으로 낚시를 할 때, 잡은 상어의 무게의 합은?
// - 각 상어는 고유의 무게를 가지며, 낚시꾼이 한 열에서 낚시를 마친 후 정해진 방향으로 정해진 속력만큼 이동한다 - 이동 중 벽을 만난 경우 반대방향으로 이동한다
// - 낚시꾼은 1열부터 차례대로 낚시를 진행하며, 해당 열에 있는 상어(들) 중 수면과 가장 가까운 상어를 낚는다
// - 낚시꾼의 이동이 끝나면 상어들이 동시에 이동하는데, 만약 한 칸에 두 마리 이상의 상어가 있게 된 경우 가장 무거운 상어가 나머지 상어(들)을 잡아먹는다

// 우선 상어 정보를 받아 상어 정보를 저장하는 배열에 저장 - 보드에서 직접 찾기 어려울 수 있으니(100*100*10000) 위치도 저장(tuple)
// 그리고 여기서 얻은 정보를 바탕으로 상어 위치를 표시하는 보드 생성, 각 상어의 인덱스를 해당 위치에 기록
// 또한 각 상어가 더 이상 없는 경우(잡히든 먹히든)을 체크하는 배열도 생성, 없는 상어에게 접근하지 않도록 함

// 이제 각 열을 순회하며 낚시 - 이동 과정 수행
// 첫 번째로 수면에서 가장 가까운 상어를 보드에서 찾아 해당 상어를 잡고 결과값에 누적시키기
// 이후 각 상어에 대해 이동 과정 수행 - 속력이 모두 소모될 때까지 해당 방향으로 이동하면서, 만약 보드 바깥으로 나간 경우 방향을 반전시키고 그 방향대로 두 칸 이동(원위치 후 이동)
// 그런데 속력이 1000까지 주어질 수 있어 단순히 한 칸씩 이동시키면 시간 초과 가능(1000*10000)
// 다행히도 수식으로 이를 축약시킬 수 있음 - s % (r - 1) * 2 -> 벽을 두 번 찍고 다시 원래대로 돌아오는 거리(최대 198)
// 방향이 1/2라면 r을, 3/4라면 c를 기준으로 나머지 연산하여 s를 간소화시킬 수 있음
// 이렇게 이동 후 초기화한 보드에 상어들의 위치를 다시 기록하는데, 이때 이미 기록된 칸에 새 상어가 들어오는 경우 무게를 비교해 더 무거운 쪽을 남기고 가벼운 쪽은 죽이기

// 무분별한 tuple 사용은 가독성에 큰 악영향을 미칩니다 - tuple 대신 struct를 만드는 습관을...