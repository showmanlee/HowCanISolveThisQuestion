// 최고의 피자
// https://www.acmicpc.net/problem/5545

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, a, b;
	cin >> n >> a >> b;
	vector<int> toppings(n);
	int dough;
	cin >> dough;
	for (int i = 0; i < n; i++)
		cin >> toppings[i];
	sort(toppings.begin(), toppings.end(), greater<int>());
	int suma = dough, sumb = a;
	int res = dough / a;
	for (int i = 0; i < n; i++) {
		suma += toppings[i];
		sumb += b;
		if (suma / sumb < res)
			break;
		res = suma / sumb;
	}
	cout << res << '\n';
}

// 도우의 가격이 A원, 열량이 서로 다른 토핑의 가격이 각 B원일 때, 토핑을 중복되지 않게 넣어 1원당 열량을 최대로 만든 결과는?

// 토핑이 종류에 관계없이 가격이 고정되어 있으므로, 원당 열량을 높이려면 열량이 높은 토핑을 먼저 사용하는 것이 유리
// 토핑을 열량 내림차순으로 정렬한 후, 토핑을 넣지 않은 상태에서부터 열량의 합 / 가격의 합으로 원당 열량을 측정
// 이후 정렬된 토핑을 하나씩 넣어보면서 넣은 상태의 원당 열량이 이전 결과보다 적게 나온다면 그 이후부터는 무조건 적어짐이 보장되므로 그 토핑을 넣지 않았을 때의 결과를 출력