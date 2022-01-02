// 연산자 끼워넣기 (2)
// https://www.acmicpc.net/problem/15658

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

// 1과 달리 연산자의 총합이 n-1개를 넘을 수 있음
// 하지만 기본적인 구조는 1과 같기 때문에, 1과 같은 코드(재귀 카운팅 기반)로 통과할 수 있음