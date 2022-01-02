// 근손실
// https://www.acmicpc.net/problem/18429

#include <iostream>
#include <vector>
using namespace std;

int n, k;
int kit[9];
bool check[9];
int order[9];
int res;

void dfs(int p) {
	if (p == n) {
		int m = 0;
		for (int i = 0; i < n; i++) {
			m += kit[order[i]];
			m -= k;
			if (m < 0)
				return;
		}
		res++;
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!check[i]) {
			check[i] = true;
			order[p] = i;
			dfs(p + 1);
			check[i] = false;
		}
	}
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> kit[i];
	res = 0;
	dfs(0);
	cout << res << '\n';
}

// 매일 k씩 발생하는 근손실을 방지하기 위해 근육량 증가량이 다른 운동 키트들을 하루에 하나씩 사용한다고 할 때, 근육량을 초기 상태 이상으로 계속 유지할 수 있는 경우의 수는?
// 운동 키트들로 만들 수 있는 순열을 모두 탐색해 조건에 맞는 경우의 개수를 찾는다 - 브루트포스
// dfs로 순열을 만든 후 직접 돌려보면서 근육량이 음수로 가능 상황이 생기지 않으면 결과에 누적