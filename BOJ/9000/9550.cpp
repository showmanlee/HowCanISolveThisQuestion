// 아이들은 사탕을 좋아해
// https://www.acmicpc.net/problem/9550

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		int n, k;
		cin >> n >> k;
		int res = 0;
		for (int i = 0; i < n; i++) {
			int p;
			cin >> p;
			res += p / k;
		}
		cout << res << '\n';
	}
}

// n종류의 사탕이 서로 다른 수만큼 주어지고 한 아이는 같은 사탕을 k개 이상 먹어야 할 때, 몇 명의 아이가 사탕을 먹을 수 있는지 구하기

// 각 사탕 개수에 따라 p / k의 합 출력하기