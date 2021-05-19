// 주유소
// https://www.acmicpc.net/problem/13305

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<long long> price(n), dist(n);
	for (int i = 1; i < n; i++)
		cin >> dist[i];
	for (int i = 0; i < n; i++)
		cin >> price[i];
	long long p = 1987654321;
	long long res = 0;
	for (int i = 1; i < n; i++) {
		if (p > price[i - 1])
			p = price[i - 1];
		res += p * dist[i];
	}
	cout << res << '\n';
}

// 일직선 도로 위에 있는 n개의 도시에는 리터 당 가격이 다른 주유소가 한 개씩 있고, 첫 도시에서 마지막 도시까지 연비가 리터당 1km인 차로 여행하려고 한다
// 이때 이동할 때 드는 기름값의 최소 비용은?

// 그리디 문제 - "부분적인 최적해가 전체적인 최적해가 되는 마법!"
// 각 지점으로 이동하면서 현재까지 만난 주유소 중 가장 저렴한 주유소에서 그보다 더 저렴한 주유소를 찾을 때까지 기름을 넣으면 됨
// 따라서 도로를 진행시키면서 해당 도로 직전에 만난 주유소가 저렴하다면 최저가를 갱신시킨 후, 도로 길이 * 최저가를 지속해서 누적하기
// 어차피 마지막 주유소는 의미가 없으니 고려하지 않아도 됨

// 이것이 그리디 아이디어 - 한동안 그리디를 중점으로 풀어볼까 합니다