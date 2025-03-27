// 게임말 올려놓기
// https://www.acmicpc.net/problem/31995

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	int res = (n - 1) * (m - 1) * 2;
	cout << res << '\n';
}

// n*m 보드에서 돌 두개를 대각선으로 이웃하게 두는 경우의 수 구하기