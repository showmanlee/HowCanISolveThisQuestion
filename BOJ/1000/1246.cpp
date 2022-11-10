// 온라인 판매
// https://www.acmicpc.net/problem/1246

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<int> v(m);
	for (int i = 0; i < m; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end(), greater<int>());
	int res = 0, price = 0;
	for (int i = 0; i < m; i++) {
		if (i >= n) {
			break;
		}
		if (res < v[i] * (i + 1)) {
			res = v[i] * (i + 1);
			price = v[i];
		}
	}
	cout << price << ' ' << res << '\n';
}

// n개의 계란을 같은 가격으로 m명의 사람들에게 하나씩 파는 상황에서 각자 살 수 있는 최대 가격이 주어질 때, 최고 수익을 얻을 수 있는 가장 낮은 가격과 그 결과 출력하기

// 사람들을 내림차순으로 정렬한 뒤, 가장 앞의 사람부터 그 사람이 원하는 가격으로 사람 수만큼 판 결과의 최대를 구하면 된다
// 물론 여기서 재고보다 많은 사람에게 팔 수는 없음 