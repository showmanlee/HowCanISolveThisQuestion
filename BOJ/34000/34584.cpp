// Take It or Double It
// https://www.acmicpc.net/problem/34584

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a, b;
	cin >> a >> b;
	cout << (a * 2 > b ? "take it" : "double it") << '\n';
}

// a의 2배가 b보다 큰지 구하기