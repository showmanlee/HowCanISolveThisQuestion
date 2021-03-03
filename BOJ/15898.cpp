// 피아의 아틀리에 ~신비한 대회의 연금술사~
// https://www.acmicpc.net/problem/15898

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class cell {
public:
	char color;
	int power;

	cell() {
		color = 'W';
		power = 0;
	}
	cell(char c, int p) : color(c), power(p) {}
	cell& operator+=(cell& a) {
		power += a.power;
		if (power > 9)
			power = 9;
		if (power < 0)
			power = 0;
		if (a.color != 'W')
			color = a.color;
		return *this;
	}
};

cell element[10][4][4][4];
int n;

vector<vector<cell>> filling(vector<vector<cell>> pot, int t, int k, int r) {
	int x = k / 2, y = k % 2;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			pot[i + x][j + y] += element[t][r][i][j];
	return pot;
}

int dfs(vector<vector<cell>> pot, vector<bool> visit, int count) {
	int ret = 0;
	if (count == 3) {
		int r = 0, b = 0, g = 0, y = 0;
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 5; j++) {
				if (pot[i][j].color == 'R')
					r += pot[i][j].power;
				if (pot[i][j].color == 'B')
					b += pot[i][j].power;
				if (pot[i][j].color == 'G')
					g += pot[i][j].power;
				if (pot[i][j].color == 'Y')
					y += pot[i][j].power;
			}
		return r * 7 + b * 5 + g * 3 + y * 2;
	}
	for (int i = 0; i < n; i++) {
		if (!visit[i]) {
			visit[i] = true;
			for (int k = 0; k < 4; k++)
				for (int r = 0; r < 4; r++) {
					vector<vector<cell>> npot = filling(pot, i, k, r);
					ret = max(ret, dfs(npot, visit, count + 1));
				}
			visit[i] = false;
		}
	}
	return ret;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++) {
				int p;
				cin >> p;
				element[k][0][i][j].power = p;
			}
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++) {
				char c;
				cin >> c;
				element[k][0][i][j].color = c;
			}
		for (int r = 1; r < 4; r++) {
			for (int i = 0; i < 4; i++)
				for (int j = 0; j < 4; j++)
					element[k][r][i][j] = element[k][r - 1][3 - j][i];
		}
	}
	vector<vector<cell>> pot(5, vector<cell>(5, cell('W', 0)));
	vector<bool> visit(n);
	cout << dfs(pot, visit, 0) << '\n';
}

// 폭탄 제조를 위해 4*4 모양 재료(회전 가능) 3개를 5*5 모양 가마에 넣을 때 가장 품질이 좋은 경우의 품질은?
// 4*4 모양의 재료는 각각의 칸마다 색깔(RGBYW)과 효능(-9~9)이 있다
// 재료를 가마에 넣을 때 가마의 각 칸은 (새로 넣은 효능 + 원래 효능(0~9 범위 내에서)), (들어간 재료가 W인 경우 원래 색깔, 아닌 경우 새로운 색깔)로 바뀐다
// 폭탄의 품질은 전체 5*5 가마에 들어간 재료의 색깔별 합에서 7R + 5B + 3G + 2Y 수식으로 계산

// 재료 수가 최대 10개로, 순서에 영향을 받지만 완전 탐색이 충분히 가능하다고 함 - 브루트포스!
// 각 재료들을 클래스화해서 입력을 받고, 입력 단에서 돌린 것도 함께 저장하기([i][j] = [3-j][i]) - 4차원 배열로 저장됨
// 이들을 바탕으로 완전탐색 수행하기 - n * (n - 1) * (n - 2) * ((4 * 4) ^ 3) ... 최소 24576, 최대 2949120회 탐색
// for문 3개 쌓이면 복잡하니까 dfs로 만들까 - pot을 매 dfs 실행 시마다 새로 만들어 할당하여 원래 pot이 망가지지 않게
// 다른 사람들 하는 것처럼 전역 배열을 만들어 입력을 받으면 실행 속도가 몇 배는 더 빨라진다 - 이를 위해서 클래스 기본 생성자를 만들 필요가 있음
// 이렇게 빠른 실행을 위한 스킬을 배워갑니다