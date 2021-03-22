// 퇴사
// https://www.acmicpc.net/problem/14501

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;

int n, res;
pr board[15];

void dfs(int p, int sum) {
	res = max(res, sum);
	if (p == n)
		return;
	for (int i = p; i < n; i++) {
		if (i + board[i].first <= n)
			dfs(i + board[i].first, sum + board[i].second);
	}
}

int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> board[i].first >> board[i].second;
	res = 0;
	for (int i = 0; i < n; i++) {
		if (i + board[i].first <= n)
			dfs(i + board[i].first, board[i].second);
	}
	cout << res << '\n';
}

// n일 후 퇴사하려는 상담사가 n일까지의 상담 일정표에서 최대의 수익을 받고 떠나기 위해 선택한 경우의 수익은?
// 상담은 한 번 잡으면 여러 날이 걸리고, 그 기간 동안은 신규 상담을 잡을 수 없다. 그리고 n일 이후에는 회사에 없기 때문에 일정 상 n일이 넘어가는 상담도 잡을 수 없다.
// 브포 - 만약 선택한 상담 시작일 + 지속일이 n을 넘지 않는다면 매개변수 sum에 추가하고 브포 함수 진입
// 일단 함수에 진입하면 sum으로 res를 갱신해 주고, 만약 소요일이 n을 넘어섰다면 탈출, 그렇지 않으면 위의 과정 반복