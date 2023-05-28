// 성장의 비약 선택권
// https://www.acmicpc.net/problem/26645

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> v(5);
	v[1] = min(n + 8, 210);
	v[2] = min(n + 4, 220);
	v[3] = min(n + 2, 230);
	v[4] = min(n + 1, 240);
	int resv = 0, res = 0;
	for (int i = 1; i <= 4; i++) {
		if (resv <= v[i]) {
			resv = v[i];
			res = i;
		}
	}
	cout << res << '\n';
}

// 200~209레벨일 때 레벨을 1 올려주는 아이템 8개, ~219일 때 1 올려주는 아이템 4개, ~229일 떄 1 올려주는 아이템 2개, ~239일 때 올려주는 아이템이 1개 있을 때, 어떤 아이템을 모두 써야 최고 레벨이 되는지 판정하기

// 각각의 아이템은 최대치 + 1 또는 현재 레벨 + 개수 중 더 적은 레벨로 올려주는 아이템 - 따라서 그 값들을 모두 구한 후 최댓값을 구해준다