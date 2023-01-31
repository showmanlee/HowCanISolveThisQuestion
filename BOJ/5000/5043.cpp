// 정말 좋은 압축
// https://www.acmicpc.net/problem/5043

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	long long n;
	int b;
	cin >> n >> b;
	long long maxx = (1ll << (b + 1)) -1;
	cout << (n <= maxx ? "yes" : "no") << '\n';
}

// 주어진 파일 n개를 b비트로 압축할 수 있는지 판정하기

// 설명이 비직관적이긴 하나, 본질적으로 말하면 최대 b비트 길이의 비트 문자열로 n개의 경우를 쓸 수 있는가를 묻는 것
// 쉽게 말해 n <= 2^b - 1을 묻는 문제긴 함 - 여기서 n은 long long 범위까지 주어질 수 있음에 주의