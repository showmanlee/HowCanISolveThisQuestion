// 피리 부는 사나이
// https://www.acmicpc.net/problem/16724

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
typedef pair<double, double> pr;
typedef pair<double, pair<int, int>> prr;

int group[1000001];

int finding(int p) {
	if (group[p] == p)
		return p;
	return group[p] = finding(group[p]);
}

void unioning(int a, int b) {
	int ga = finding(a), gb = finding(b);
	if (ga > gb)
		group[ga] = gb;
	else
		group[gb] = ga;
}

int main(void) {
	int n, m;
	cin >> n >> m;
	vector<vector<char>> board(n, vector<char>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			group[i * m + j] = i * m + j;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 'U')
				unioning(i * m + j, (i - 1) * m + j);
			if (board[i][j] == 'D') 
				unioning(i * m + j, (i + 1) * m + j);
			if (board[i][j] == 'L')
				unioning(i * m + j, i * m + (j - 1));
			if (board[i][j] == 'R')
				unioning(i * m + j, i * m + (j + 1));
		}
	}
	set<int> res;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			res.insert(finding(i * m + j));
	cout << res.size() << '\n';
}

// n*m 보드에서 각 칸에서 피리 부는 사나이에 의해 움직이는 방향이 주어질 때, 이동을 막을 수 있는 안전 구역을 놓을 수 있는 최소 개수는?

// 움직이는 방향으로 보드를 벗어날 수는 없음 - 따라서 필연적으로 사이클이 발생함(그것이 원형이 아니더라도)
// 안전 구역은 사이클의 종점(6 형태의 사이클의 삼거리 지점 또는 O 형태의 사이클의 꼭짓점)에만 놓는 것이 효과적이라고 볼 수 있음
// 따라서 이 문제는 '각 칸마다 방향이 적힌 n*m 보드에서 볼 수 있는 사이클의 수 구하기'로 볼 수 있음

// 사이클 판정은 union-find가 전문 - 2차원 공간에서는 좌표값을 1차원 값으로 바꿔서 활용할 수 있다
// 우선 보드를 받은 다음, 각 칸에 적힌 방향에 있는 칸을 union해주어 같은 사이클에 포함시킨다
// 이후 find를 돌려주며 등장한 사이클의 개수를 센 뒤, 이를 결과로 출력한다
// 사이클의 개수를 세기 위해 set을 활용할 수 있음 - 사이클 번호를 중복이 허용되지 않는 set에 계속 삽입하면 고유값들만 남게 되니 