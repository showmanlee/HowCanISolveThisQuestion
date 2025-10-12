// 소대 배정
// https://www.acmicpc.net/problem/34619

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a, b, n, k;
	cin >> a >> b >> n >> k;
	int x = 1, y = 1, z = 0, cnt = k;
	while (cnt > 0) {
		cnt--;
		z++;
		if (z > n) {
			y++;
			z = 1;
			if (y > b) {
				x++;
				y = 1;
			}
		}
	}
	cout << x << ' ' << y << '\n';
}

// n명이 배치되는 소대 a개로 구성된 중대 b개가 있을 때, k번째 병사가 배치되는 중대와 소대 구하기