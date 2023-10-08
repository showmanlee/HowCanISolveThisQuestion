// 스위트콘 가격 구하기
// https://www.acmicpc.net/problem/30030

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	n = n / 11 * 10;
	cout << n << '\n';
}

// 부가세 10%가 포함된 가격의 원가 구하기

// n / 11 * 10