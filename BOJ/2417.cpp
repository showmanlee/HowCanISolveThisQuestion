// 정수 제곱근
// https://www.acmicpc.net/problem/2417

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	long long n;
	cin >> n;
	long long q = ceil(sqrt(n));
	cout << q << '\n';
}

// long long 범위 n의 정수 제곱근(q^2 >= n)은?

// 제곱하여 n 이상이 나오는 정수 중 가장 작은 수를 찾아라
// sqrt를 하여 실수 제곱근을 찾고, 여기에 ceil(올림) 연산을 하면 답이 나옴
// 이분 탐색으로 찾는 방법도 있긴 하지만 이게 더 편하긴 함