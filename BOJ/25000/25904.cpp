// 안녕 클레오파트라 세상에서 제일가는 포테이토칩
// https://www.acmicpc.net/problem/25904

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, x;
	cin >> n >> x;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	int p = 0;
	while (true) {
		if (x > v[p % n]) {
			cout << (p % n + 1) << '\n';
			break;
		}
		p++;
		x++;
	}
}

// 턴을 넘길 때마다 음계가 1씩 올라가는 클레오파트라 게임을 할 때 시작하는 음계와 각 플레이어가 낼 수 있는 최대 음계가 주어질 때, 누구에서 게임이 끊기는지 확인하기

// 1씩 올라가는 x를 각자의 턴의 비교해보고 x가 더 큰 상황일 때 탈락 판정하기