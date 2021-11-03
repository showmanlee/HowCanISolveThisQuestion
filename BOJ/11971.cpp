// 속도 위반
// https://www.acmicpc.net/problem/11971

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<int> board(100);
	int cur = 0;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		for (int j = cur; j < cur + a; j++) {
			board[j] = b;
		}
		cur += a;
	}
	cur = 0;
	int res = 0;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		for (int j = cur; j < cur + a; j++) {
			res = max(res, b - board[j]);
		}
		cur += a;
	}
	cout << res << '\n';
}

// 도로 100km의 구간별 속도제한과 달린 속도가 주어질 때, 속도를 위반한 최댓값은?

// 도로는 언제나 100km고, 도로 구간은 정수 범위 안에 있음이 보장됨
// 따라서 각 km별 제한 속도를 100칸들이 배열에 나타낼 수 있음 - 범위를 구해서 배열에 삽입
// 이후 같은 방식으로 달린 속도의 범위를 구한 후, 현재 속도와 현재 제한의 차 중 최대를 구해 출력한다