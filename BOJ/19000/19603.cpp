// Epidemiology
// https://www.acmicpc.net/problem/19603

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int p, n, r;
	cin >> p >> n >> r;
	int t = n;
	int sum = 0;
	for (int i = 0; ; i++) {
		sum += t;
		if (sum > p) {
			cout << i << '\n';
			break;
		}
		t *= r;
	}
}

// 최초 감염자 수와 전파량이 주이닐 때 p명이 감염되는 날짜 구하기