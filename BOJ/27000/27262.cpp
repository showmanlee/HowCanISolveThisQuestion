// Лифт
// https://www.acmicpc.net/problem/27262

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, k, a, b;
	cin >> n >> k >> a >> b;
	cout << ((n + k - 2) * b) << ' ' << ((n - 1) * a) << '\n';
}

// 층당 b초의 시간이 걸리는 엘리베이터, 층당 a초가 걸리는 계단이 있는 건물에서 1층에서 n층으로 올라가기 위해 현재 k층에 있는 엘리베이터를 기다릴 수 있을 때, 엘리베이터를 기다렸다 타고 올라갈 때와 걸어갈 때 걸리는 시간 구하기

// 1층부터 n층까지 걸리는 시간은 (n-1)p초 - 이를 이용해 계산해봅시다