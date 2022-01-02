// 부분수열의 합
// https://www.acmicpc.net/problem/14225

#include <iostream>
#include <vector>
using namespace std;

int n;
int board[21];
bool selected[21];
bool shown[2000002];

void dfs(int p) {
	if (p == n) {
		int sum = 0;
		for (int i = 0; i < n; i++)
			if (selected[i])
				sum += board[i];
		shown[sum] = true;
		return;
	}
	selected[p] = true;
	dfs(p + 1);
	selected[p] = false;
	dfs(p + 1);
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> board[i];
	dfs(0);
	int res = 1;
	while (true) {
		if (!shown[res])
			break;
		res++;
	}
	cout << res << '\n';
}

// 수열이 주어졌을 때, 부분 수열의 합으로 나올 수 없는 가장 작은 자연수 구하기
// 수열의 길이는 최대 20, 수열 원소는 최대 100000 - 나올 수 있는 합의 크기는 최대 200만
// 200만 정도면 큰 부담 없이 마킹 배열 체제로 운영할 수 있음 - 브루트포스 DFS로 부분수열에 참여할 수를 고르고, 그 수를 모두 더한 값을 마킹 배열에 체크
// 이후 마킹 배열을 순회하면서 처음으로 체크되지 않은 곳이 바로 답