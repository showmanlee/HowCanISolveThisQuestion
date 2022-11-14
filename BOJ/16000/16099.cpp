// Larger Sport Facility
// https://www.acmicpc.net/problem/16099

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		long long a, b, c, d;
		cin >> a >> b >> c >> d;
		if (a * b > c * d) {
			cout << "TelecomParisTech\n";
		} else if (a * b < c * d) {
			cout << "Eurecom\n";
		} else {
			cout << "Tie\n";
		}
	}
}

// 양쪽의 직사각형 크기가 주어졌을 때, 누가 더 큰지 출력하기

// 해보세요