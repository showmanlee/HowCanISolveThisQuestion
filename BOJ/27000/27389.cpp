// Metronome
// https://www.acmicpc.net/problem/27389

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cout << fixed;
	cout.precision(2);

	float n;
	cin >> n;
	cout << (n / 4) << '\n';
}

// n / 4를 소수 둘째자리까지 구하기

// cout.precision(2)