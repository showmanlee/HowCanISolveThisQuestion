// 뮤탈리스크
// https://www.acmicpc.net/problem/12869

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <string>
#include <algorithm>
using namespace std;
typedef tuple<int, int, int> tpp;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> v(3);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	vector<vector<vector<int>>> board(61, vector<vector<int>>(61, vector<int>(61, -1)));
	board[v[0]][v[1]][v[2]] = 0;
	vector<string> p = {"931", "913", "391", "319", "193", "139"};
	queue<tpp> q;
	q.push({v[0], v[1], v[2]});
	while (!q.empty()) {
		int a = get<0>(q.front());
		int b = get<1>(q.front());
		int c = get<2>(q.front());
		q.pop();
		if (a == 0 && b == 0 && c == 0) {
			break;
		}
		for (int i = 0; i < 6; i++) {
			int aa = max(a - p[i][0] + '0', 0);
			int bb = max(b - p[i][1] + '0', 0);
			int cc = max(c - p[i][2] + '0', 0);
			if (board[aa][bb][cc] == -1) {
				board[aa][bb][cc] = board[a][b][c] + 1;
				q.push({aa, bb, cc});
			}
		}
	}
	cout << board[0][0][0] << '\n';
}

// scv들의 남은 체력들이 주어질 때, 한 번에 각자 다른 scv에게 9/3/1의 피해를 입힐 수 있는 뮤탈리스크가 scv들을 모두 죽이는데 필요한 최소 시간 구하기

// bfs - 분기는 9/3/1 배치 순서, 시작점은 현재 SCV의 체력(2마리 이하인 경우 남은 칸을 0으로 두고 계산)
// 시작점에서 케이스를 구분하여 계속 채우다가 0,0,0을 만나면 중단하고 출력하기