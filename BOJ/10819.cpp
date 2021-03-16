// 차이를 최대로
// https://www.acmicpc.net/problem/10819

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int n, res;
int board[8], a[8];
bool visit[8];

void dfs(int count) {
	if (count == n) {
		int ret = 0;
		for (int i = 0; i < n - 1; i++)
			ret += abs(a[i] - a[i + 1]);
		res = max(res, ret);
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!visit[i]) {
			visit[i] = true;
			a[count] = board[i];
			dfs(count + 1);
			visit[i] = false;
		}
	}
}

int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> board[i];
	res = 0;
	dfs(0);
	cout << res << '\n';
}

// 수열을 적당히 재배치하여 |a[0] - a[1]| + |a[1] - a[2]| + ... 꼴 식의 최댓값 구하기
// '수열을 적당히 배치하라', n <= 8 = 재귀를 통한 백트래킹으로 풀 수 있음