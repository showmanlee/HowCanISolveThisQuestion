// 브실이의 불침번 근무
// https://www.acmicpc.net/problem/29719

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

	long long n, m;
	cin >> n >> m;
	long long a = 1, b = 1;
	for (int i = 0; i < n; i++) {
		a = (a * m) % 1000000007;
		b = (b * (m - 1)) % 1000000007;
	}
	long long res = (1000000007 + a - b) % 1000000007;
	cout << res << '\n';
}

// n명을 중복 포함하여 m개 뽑아 순열을 만들 때, 그 중 한 명이 순열에 들어가는 경우의 수 출력하기

// 그 중 한 명이 순열에 들어가지 않는 경우는 n-1명으로 순열을 만드는 경우의 수
// 중복 포함 순열의 경우의 수는 n^m
// 따라서 n^m - (n-1)^m을 구해준다