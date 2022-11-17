// 할아버지는 유명해!
// https://www.acmicpc.net/problem/5766

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	while (true) {
		int n, m;
		cin >> n >> m;
		if (n == 0 && m == 0) {
			break;
		}
		vector<int> player(10001);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int p;
				cin >> p;
				player[p]++;
			}
		}
		int max = 0, res = 0;
		for (int i = 1; i <= 10000; i++) {
			if (player[i] > max) {
				res = max;
				max = player[i];
			} else if (player[i] > res && max != player[i]) {
				res = player[i];
			}
		}
		for (int i = 1; i <= 10000; i++) {
			if (player[i] == res) {
				cout << i << ' ';
			}
		}
		cout << '\n';
	}
}

// 1~10000번 선수가 있는 주간 랭킹 보드에 오른 선수들이 1점씩 획득할 때, 2위 선수 명단 구하기

// 랭킹 보드를 모두 받으면서 번호가 나올 때 그 사람의 점수를 늘려둔다
// 이후 모든 선수의 점수를 보면서 최대치를 갱신해주는데, 만약 최대치가 갱신되는 경우 그 시점에서 다음 갱신치가 2등이 된다
// 물론 2위만 갱신될 수 있으므로 그것도 체크해줘야 함 - 새로 들어온 점수가 1등과 같지 않은데 2등보다 큰 경우 2등 갱신