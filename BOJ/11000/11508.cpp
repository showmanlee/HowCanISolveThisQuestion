// 2+1 세일
// https://www.acmicpc.net/problem/11508

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> products(n);
	for (int i = 0; i < n; i++)
		cin >> products[i];
	sort(products.begin(), products.end(), greater<int>());
	long long res = 0;
	for (int i = 0; i < n; i++) {
		if (i % 3 != 2)
			res += products[i];
	}
	cout << res << '\n';
}

// 가격이 서로 다른 물건 중 아무거나 3개를 묶으면 그중 가장 싼 물건을 무료로 살 수 있을 때, 주어진 물건을 모두 구입하는데 드는 최소 비용은?

// 최대한 가장 비싼 물건을 지우는 것이 이득 - 그리고 그러려면 최대한 비싼 물건이 묶는 것들 중 가장 싼 것이 되게 하여 무료화해야 함
// 이를 위해 물건들을 내림차순으로 정렬한 뒤, 앞에서부터 3개씩 묶어나가기
// 즉, 내림차순 정렬한 물건들을 순회하며 매 3번째 물건의 가격은 카운트하지 않고 합을 모두 구하여 출력