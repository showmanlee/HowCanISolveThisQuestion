// 연산자 끼워넣기
// https://www.acmicpc.net/problem/14888

#include <iostream>
#include <vector>
using namespace std;

int n, minn, maxx;
int nums[11];

void dfs(int count, int res, int a, int s, int m, int d) {
	if (count >= n) {
		if (minn > res)
			minn = res;
		if (maxx < res)
			maxx = res;
		return;
	}
	if (a > 0)
		dfs(count + 1, res + nums[count], a - 1, s, m, d);
	if (s > 0)
		dfs(count + 1, res - nums[count], a, s - 1, m, d);
	if (m > 0)
		dfs(count + 1, res * nums[count], a, s, m - 1, d);
	if (d > 0)
		dfs(count + 1, res / nums[count], a, s, m, d - 1);
}

int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> nums[i];
	int a, s, m, d;
	cin >> a >> s >> m >> d;

	minn = 2100000000;
	maxx = -2100000000;
	dfs(1, nums[0], a, s, m, d);
	cout << maxx << '\n' << minn << '\n';
}

// n개의 수 사이에 주어진 연산자를 끼워넣은 최댓값과 최솟값 출력하기
// 연산은 우선순위에 관계없이 앞에서부터 수행한다
// 재귀함수를 이용한 백트래킹 문제 - 연산자 수도 체크해줘야 함
// 처음에 0번 수부터 넣고 시작, 이후 상황에 따라 연산자 넣어서 dfs 확장하기