// ПРАВОЪГЪЛНИК
// https://www.acmicpc.net/problem/31260

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	long long n, m, d;
	cin >> n >> m >> d;
	n = n * 100 + m;
	long long a = (n + d * 2) / 4;
	long long b = (n - d * 2) / 4;
	cout << (a / 100) << ' ' << (a % 100) << '\n' << (b / 100) << ' ' << (b % 100) << '\n';
}

// 직사각형의 둘레와 긴변과 짧은편의 차가 주어질 때, 각 변의 길이 구하기