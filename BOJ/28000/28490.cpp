// Area
// https://www.acmicpc.net/problem/28490

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int res = 0;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		res = max(res, a * b);
	}
	cout << res << '\n';
}

// 가로-세로 쌍들이 주어질 때, 넓이의 최댓값 구하기

// 구해줍시다