// 특식 배부
// https://www.acmicpc.net/problem/27110

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, a, b, c;
	cin >> n >> a >> b >> c;
	int res = min(a, n) + min(b, n) + min(c, n);
	cout << res << '\n';
}

// 세 가지 종류의 치킨을 n마리씩 사고 각 치킨을 선호하는 사람의 수가 주어졌을 때, 원하는 치킨을 먹을 수 있는 사람의 수는?

// 모든 종류에 대해 n보다 작으면 그만큼, 같거나 크면 n만큼이 먹을 수 있다