// ICONS
// https://www.acmicpc.net/problem/3276

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int a = 1, b = 1;
	while (n > a * b) {
		if (a > b) {
			b++;
		} else {
			a++;
		}
	}
	cout << a << ' ' << b << '\n';
}

// 한 칸에 돌을 하나씩 넣을 수 있는 격자에 주어진 개수의 돌을 넣으려고 할 때, 가로와 세로의 합을 최소로 한 결과는?

// 가로/세로의 합이 최소가 되려면 차가 최소가 되어야 함 - 이를 기반으로 브루트포스 계산
// 가로와 세로를 모두를 담을 수 있을 떄까지 하나씩 늘립니다