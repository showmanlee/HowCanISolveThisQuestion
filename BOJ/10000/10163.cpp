// 색종이
// https://www.acmicpc.net/problem/10163

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<vector<int>> board(1001, vector<int>(1001));
	int n;
	cin >> n;
	for (int t = 1; t <= n; t++) {
		int x, y, w, h;
		cin >> x >> y >> w >> h;
		for (int i = x; i < x + w; i++)
			for (int j = y; j < y + h; j++)
				board[i][j] = t;
	}
	vector<int> ctr(n + 1);
	for (int i = 0; i <= 1000; i++)
		for (int j = 0; j <= 1000; j++)
			ctr[board[i][j]]++;
	for (int i = 1; i <= n; i++)
		cout << ctr[i] << '\n';
}

// 1001*1001 보드에 가로 세로 길이가 다른 색종이들이 주어질 때 해당 색종이를 각자의 좌표에 순서대로 붙여 각 색종이별로 보이는 면적 출력하기

// 실제로 색종이 보드에 붙여보면 됨 - 각자의 출발 좌표부터 가로 세로 길이만큼 해당 번호로 채우는 과정을 반복(덮어쓰기도 하면서)
// 이후 보드를 순회하며 숫자들의 등장 횟수를 센 후, 그 수를 순서대로 출력하기