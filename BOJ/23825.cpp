// SASA 모형을 만들어보자
// https://www.acmicpc.net/problem/23825

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	cout << (min(n, m) / 2) << '\n';
}

// S n개와 A m개로 S와 A가 2개 필요한 SASA를 만들 때, 만들 수 있는 SASA의 최대 개수는?

// 둘 중 적은 쪽의 개수를 보면 됨 - 많은 쪽은 이미 그만큼 확보되었다는 거니
// 따라서 적은 쪽 / 2가 만들 수 있는 최대 개수