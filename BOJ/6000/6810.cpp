// ISBN
// https://www.acmicpc.net/problem/6810

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int p = 9 * 1 + 7 * 3 + 8 * 1 + 0 * 3 + 9 * 1 + 2 * 3 + 1 * 1 + 4 * 3 + 1 * 1 + 8 * 3;
	int a, b, c;
	cin >> a >> b >> c;
	cout << "The 1-3-sum is " << (p + a * 1 + b * 3 + c * 1) << '\n';
}

// 9780921418으로 시작하는 ISBN 13자리 중 뒤 3자리가 주어졌을 떄, 각 자릿수 별로 1과 3을 교대로 곱한 합 구하기

// 구하면 됩니다 - a와 c는 *1, b는 *3