// 부분수열의 합
// https://www.acmicpc.net/problem/1182

#include <iostream>
#include <vector>
using namespace std;

int n, s, board[20];
int res;

void dfs(int count, int sum){
	if (count >= n)
		return;
	sum += board[count];
	if (sum == s)
		res++;
	dfs(count + 1, sum);
	dfs(count + 1, sum - board[count]);
}

int main(void) {
	cin >> n >> s;
	for (int i = 0; i < n; i++)
		cin >> board[i];
	res = 0;
	dfs(0, 0);
	cout << res << '\n';
}

// 한 수열의 부분수열의 합이 s가 나오는 경우의 수는?
// 재귀함수로 백트래킹 - 해당 수를 더한 케이스, 그렇지 않은 케이스로 나눠서 계속 나아가기
// 중단 조건은 count가 n을 넘어섰을 때만