// Rats
// https://www.acmicpc.net/problem/18301

#include <iostream>
using namespace std;

int main(void) {
	int a, b, c;
	cin >> a >> b >> c;
	int res = (a + 1) * (b + 1) / (c + 1) - 1;
	cout << res << '\n';
}

// floor((a + 1) * (b + 1) / (c + 1) - 1) 구하기
// 그냥 적혀있는 대로...