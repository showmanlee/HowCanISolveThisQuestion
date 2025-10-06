// Roller Coaster Ride
// https://www.acmicpc.net/problem/34454

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, c, p;
	cin >> n >> c >> p;
	cout << (n <= c * p ? "yes" : "no") << '\n';
}

// p명이 탈 수 있는 c개의 차가 있는 기차에 n번째 줄에서 탈 수 있는지 구하기