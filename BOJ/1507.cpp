// 궁금한 민호
// https://www.acmicpc.net/problem/1507

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<vector<int>> board(n, vector<int>(n));
	vector<vector<int>> dist(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			dist[i][j] = board[i][j];
		}
	}
	int res = 0;
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == k || k == j)
					continue;
				if (board[i][j] > board[i][k] + board[k][j])
					res = -1;
				else if (board[i][j] == board[i][k] + board[k][j])
					dist[i][j] = 0;
				if (res == -1)
					break;
			}
			if (res == -1)
				break;
		}
		if (res == -1)
			break;
	}
	if (res != -1) {
		for (int i = 0; i < n; i++)
			for (int j = i; j < n; j++)
				res += dist[i][j];
	}
	cout << res << '\n';
}

// 양방향 도로로 이어진 각 도시 간의 최단 거리를 나타낸 인접행렬이 주어졌을 때, 해당 최단 거리들을 유지할 수 있는 도로를 최소한으로 남긴 상태의 도로 길이의 합 구하기

// 주어진 배열은 이미 최단거리임 - 우리가 할 일은 이 배열의 정보들이 정당한지, 그리고 없애도 되는 곳이 있는지 확인하는 것
// 따라서 플로이드를 다른 방법으로 돌려줘야 함 - 최단 거리 플로이드 확인용 플로이드
// 없애도 되는 경우 - i-j간의 거리가 i-k + k-j 거리와 같은 경우 - 이 경우에는 i-k-j로 돌아가도 최단 거리가 유지되기에 긴 도로 i-j는 지워도 된다
// 정당하지 않은 경우 - i-j간의 거리가 i-k + k-j 거리보다 긴 경우 - 이 경우(최단 거리 플로이드에서 갱신되는 경우)에는 제대로 최단 거리가 갱신되지 않은 것
// 따라서 이 경우가 발생하면 플로이드 탐색 즉시 종료하기
// 만약 해당 보드가 정당하다면, 지워진 도로를 제외한 나머지 도로의 길이를 모두 더해 결과 출력하기 - 배열 대각선 절반만 돌리기

// 주어진 배열과 같은 크기와 값을 가지는 배열을 하나 더 만들어주고, 거기서 도로 지워주기 - 원래 배열에서 지우면 오류 발생